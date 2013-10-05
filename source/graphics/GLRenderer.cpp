#include "GLRenderer.h"

#include "engine/Engine.h"

#include "GLShader.h"

#include <GL/glew.h>
#include <SDL_opengl.h>

#include <glm/glm.hpp>

#include "game/Chunk.h"
#include "game/MeshComponent.h"
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
    "  outColor = vec4(triangleColor, 1.0 );"
    "}";

  // Create a Vertex Buffer Object and copy the vertex data to it
  std::shared_ptr<GLShader> vertexShader = std::make_shared<GLShader>(GL_VERTEX_SHADER, vertexSource);
  // Create and compile the vertex shader
  // vertexShader = glCreateShader(GL_VERTEX_SHADER);
  // glShaderSource(vertexShader, 1, &vertexSource, NULL);
  // glCompileShader(vertexShader);

  // GLint stat;

  // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &stat);

  // if (stat == GL_FALSE) {
  //   char buffer[512];
  //   glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
  //   printf("%s", buffer);
  // }
  std::shared_ptr<GLShader> fragmentShader = std::make_shared<GLShader>(GL_FRAGMENT_SHADER, fragmentSource);
  // Create and compile the fragment shader
  // fragmentShader = glCreateShader( GL_FRAGMENT_SHADER);
  // glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  // glCompileShader(fragmentShader);

  // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &stat);

  // if (stat == GL_FALSE) {
  //   char buffer[512];
  //   glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
  //   printf("%s", buffer);
  // }

  std::vector<std::shared_ptr<GLShader>> shaders;
  shaders.push_back(vertexShader);
  shaders.push_back(fragmentShader);

  program_ = std::make_shared<GLProgram>(shaders);
  program_->Use();
  // shaderProgram = glCreateProgram();
  // glAttachShader(shaderProgram, vertexShader);
  // glAttachShader(shaderProgram, fragmentShader);
  // glBindFragDataLocation(shaderProgram, 0, "outColor");
  // glLinkProgram(shaderProgram);

  // GLint status;
  // glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
  // if (status == GL_FALSE) {
  //   printf("program compilation failed\n");
  //   std::string msg("Program linking failure: ");
    
  //   GLint infoLogLength;
  //   glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
  //   char* strInfoLog = new char[infoLogLength + 1];
  //   glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
  //   msg += strInfoLog;
  //   printf("%s\n", msg.c_str());
  //   delete[] strInfoLog;
    
  //   glDeleteProgram(shaderProgram); shaderProgram = 0;
  // }

  // glUseProgram(shaderProgram);

  // // Specify the layout of the vertex data
  // GLuint pos = program_->attribute("position");
  // glEnableVertexAttribArray(pos);
  // glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

  // Get the location of the color uniform
  program_->uniform("triangleColor");
  program_->uniform("camera");
  // uniColor = glGetUniformLocation(shaderProgram, "triangleColor");
  // uniCamera = glGetUniformLocation(shaderProgram, "camera");

  // Game::Chunk chunk(16, 16, 16);
  // chunk.Fill();

  // auto mesh_component = chunk.GetComponent<Game::MeshComponent>("mesh").lock();

  // if (!mesh_component) return false;

  // auto &mesh = mesh_component->GetMesh();

  // glGenVertexArrays(1, &vao);
  // glBindVertexArray(vao);
  // glGenBuffers(1, &vbo);
  // glBindBuffer(GL_ARRAY_BUFFER, vbo);
  // glBufferData(GL_ARRAY_BUFFER, mesh->GetVertices().size() * sizeof(glm::vec3), &mesh->GetVertices()[0], GL_STATIC_DRAW);
  // GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  // glEnableVertexAttribArray(posAttrib);
  // glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
  return true;
}

void GLRenderer::registerMesh(std::shared_ptr<Mesh> mesh) {
  //glBindBuffer(GL_ARRAY_BUFFER, vbo);
  //glBufferData(GL_ARRAY_BUFFER, mesh->GetVertices().size() * sizeof(glm::vec3), &mesh->GetVertices()[0], GL_STATIC_DRAW);

  this->meshes_.push_back(std::make_shared<GLMesh>(mesh, program_));
}

GLRenderer::~GLRenderer() {
}

void GLRenderer::Render() {
  // Set the color of the triangle
  float time = (float)clock() / (float)CLOCKS_PER_SEC;

  // glUniform3f(uniColor, (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);
  program_->setUniform("triangleColor", (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);

  // glUniformMatrix4fv(uniCamera, 1, GL_FALSE, glm::value_ptr(this->camera_.viewProjection()));
  program_->setUniform("camera", camera_.viewProjection());

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(36));

  // for (auto &mesh : meshes_) {
  //   mesh->Bind();
  //   auto count = mesh->vertCount();
  //   glDrawArrays(GL_TRIANGLES, 0, count);
  // }
}

} // Graphics
} // Coasters
