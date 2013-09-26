#include "Renderer.h"

#include "engine/RendererEvent.h"
#include "GLRenderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ctime>
#include <cmath>

namespace Coasters {
namespace Graphics {

GLRenderer::GLRenderer() : chunk_(16, 16, 16) {}

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
    "  outColor = vec4( triangleColor, 1.0 );"
    "}";

  // Create Vertex Array Object
  glGenVertexArrays( 1, &vao );
  glBindVertexArray( vao );

  // Create a Vertex Buffer Object and copy the vertex data to it
  glGenBuffers( 1, &vbo );

  this->chunk_.Fill();

  float vertices[] = {
    0.0f, 0.5f,
    0.5f, -0.5f,
    -0.5f, -0.5f
  };

  auto verts = this->chunk_.mesh_.GetVertices();

  printf("verts: %d\n", verts.size());
  printf("triangles: %d\n", this->chunk_.mesh_.GetTriangleCount());

  glBindBuffer( GL_ARRAY_BUFFER, vbo );
  glBufferData( GL_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), &verts[0], GL_STATIC_DRAW );

  // Create and compile the vertex shader
  vertexShader = glCreateShader( GL_VERTEX_SHADER );
  glShaderSource( vertexShader, 1, &vertexSource, NULL );
  glCompileShader( vertexShader );

  GLint stat;

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &stat);

  if (stat == GL_FALSE) {
    char buffer[512];
    glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
    printf("%s", buffer);
  }

  // Create and compile the fragment shader
  fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
  glShaderSource( fragmentShader, 1, &fragmentSource, NULL );
  glCompileShader( fragmentShader );

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &stat);

  if (stat == GL_FALSE) {
    char buffer[512];
    glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
    printf("%s", buffer);
  }
  // Link the vertex and fragment shader into a shader program
  shaderProgram = glCreateProgram();
  glAttachShader( shaderProgram, vertexShader );
  glAttachShader( shaderProgram, fragmentShader );
  glBindFragDataLocation( shaderProgram, 0, "outColor" );
  glLinkProgram( shaderProgram );
  glUseProgram( shaderProgram );

  // Specify the layout of the vertex data
  GLint posAttrib = glGetAttribLocation( shaderProgram, "position" );
  glEnableVertexAttribArray( posAttrib );
  glVertexAttribPointer( posAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0 );

  // Get the location of the color uniform
  uniColor = glGetUniformLocation( shaderProgram, "triangleColor" );
  uniCamera = glGetUniformLocation( shaderProgram, "camera" );
  // this->camera_.setPosition(glm::vec3(0.0f, 2.0f, -15.0f));
  // this->camera_.setLens(0.25f*3.1415f, 800 / 600, 1.0f, 1000.0f);
  // this->camera_.lookAt(glm::vec3(0, 0, 1), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
  // this->camera_.updateViewMatrix();

  return true;
}

GLRenderer::~GLRenderer() {
  glDeleteProgram( shaderProgram );
  glDeleteShader( fragmentShader );
  glDeleteShader( vertexShader );

  glDeleteBuffers( 1, &vbo );

  glDeleteVertexArrays( 1, &vao );
}

void GLRenderer::OnEvent(std::shared_ptr<Engine::RendererEvent> event) {
  switch (event->subject()) {
    case Engine::RendererEvent::Subject::MeshAdded:
      // MeshEvent &mevent = static_cast<MeshEvent &>(event);
      break;
    case Engine::RendererEvent::Subject::MeshRemoved:
      break;
  }
}

void GLRenderer::Render() {
    // Set the color of the triangle
    float time = (float)clock() / (float)CLOCKS_PER_SEC;
    glUniform3f( uniColor, ( sin( time * 4.0f ) + 1.0f ) / 2.0f, 0.0f, 0.0f );
    glUniformMatrix4fv(uniCamera, 1, GL_FALSE, glm::value_ptr(this->camera_.viewProjection()));

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    glDrawArrays( GL_TRIANGLES, 0, this->chunk_.mesh_.GetVertices().size());
}

} // Graphics
} // Coasters
