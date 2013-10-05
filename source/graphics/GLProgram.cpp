#include "GLProgram.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ctime>
#include <cmath>

namespace Coasters {
namespace Graphics {

GLProgram::GLProgram(const std::vector<std::shared_ptr<GLShader>> &shaders) {
  program_ = glCreateProgram();
  printf("made program\n");

  for (auto &shader : shaders)
    glAttachShader(program_, shader->resource());

  glBindFragDataLocation(program_, 0, "outColor");
  glLinkProgram(program_);

  GLint status;
  glGetProgramiv(program_, GL_LINK_STATUS, &status);
  if (status == GL_FALSE) {
    printf("program compilation failed\n");
    std::string msg("Program linking failure: ");
    
    GLint infoLogLength;
    glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &infoLogLength);
    char* strInfoLog = new char[infoLogLength + 1];
    glGetProgramInfoLog(program_, infoLogLength, NULL, strInfoLog);
    msg += strInfoLog;
    printf("%s\n", msg.c_str());
    delete[] strInfoLog;
    
    glDeleteProgram(program_); program_ = 0;
  }

  for (auto &shader : shaders)
    glDetachShader(program_, shader->resource());
}

GLProgram::~GLProgram() {
  printf("destroyed program\n");
  glDeleteProgram(program_);
}

void GLProgram::Use() {
  glUseProgram(program_);
}

bool GLProgram::IsInUse() {
  GLint currentProgram = 0;
  glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgram);
  return currentProgram == program_;
}

void GLProgram::StopUsing() {
  glUseProgram(0);
}

} // Graphics
} // Coasters
