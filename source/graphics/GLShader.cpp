#include "GLShader.h"

namespace Coasters {
namespace Graphics {

GLShader::GLShader(GLenum type, const std::string &source) :
  type_(type) {
  shader_ = glCreateShader(type);
  printf("made shader\n");
  const char *code = source.c_str();
  glShaderSource(shader_, 1, static_cast<const GLchar **>(&code), NULL);
  glCompileShader(shader_);

  GLint stat;

  glGetShaderiv(shader_, GL_COMPILE_STATUS, &stat);

  if (stat == GL_FALSE) {
    printf("shader compile failure\n");
    char buffer[512];
    glGetShaderInfoLog(shader_, 512, NULL, buffer);
    printf("%s", buffer);
  }
}

GLShader::~GLShader() {
  printf("destroying shader\n");
  glDeleteShader(shader_);
}

} // Graphics
} // Coasters
