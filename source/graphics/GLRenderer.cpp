#include "GLRenderer.h"

#include "engine/Engine.h"

#include "GLShader.h"

#include <GL/glew.h>
#include <SDL_opengl.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ctime>
#include <cmath>

namespace Coasters {
namespace Graphics {

GLRenderer::GLRenderer() {}

bool GLRenderer::Initialize() {
  glewExperimental = GL_TRUE;
  glewInit();

  const char* vertexSource =
    "#version 150\n"
    "uniform mat4 camera;"
    "in vec3 position;"
    "void main() {"
    "  gl_Position = camera * vec4( position, 1.0 );"
    "}";
  const char* fragmentSource =
    "#version 150\n"
    "out vec4 outColor;"
    "uniform vec3 triangleColor;"
    "void main() {"
    "  outColor = vec4( 0.0, 1.0, 0.0, 1.0 );"
    "}";

  GLShader vertexShader(GL_VERTEX_SHADER, vertexSource);
  GLShader fragmentShader(GL_FRAGMENT_SHADER, fragmentSource);

  std::vector<GLShader> shaders;
  shaders.push_back(vertexShader);
  shaders.push_back(fragmentShader);

  program_ = std::make_shared<GLProgram>(shaders);
  program_->Use();

  // Specify the layout of the vertex data
  GLuint pos = program_->attribute("position");
  glEnableVertexAttribArray(pos);
  glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

  // Get the location of the color uniform
  program_->uniform("triangleColor");
  program_->uniform("camera");

  return true;
}

void GLRenderer::registerMesh(std::shared_ptr<Mesh> mesh) {
  this->meshes_.push_back(std::make_shared<GLMesh>(mesh));
}

GLRenderer::~GLRenderer() {
}

void GLRenderer::Render() {
  // Set the color of the triangle
  float time = (float)clock() / (float)CLOCKS_PER_SEC;

  //glUniform3f(uniColor, (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);
  program_->setUniform("triangleColor", (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);

  //glUniformMatrix4fv(uniCamera, 1, GL_FALSE, glm::value_ptr(this->camera_.viewProjection()));
  program_->setUniform("camera", glm::value_ptr(camera_.viewProjection()));

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  for (auto &mesh : meshes_)
    glDrawArrays(GL_TRIANGLES, 0, mesh->vertCount());
}

} // Graphics
} // Coasters
