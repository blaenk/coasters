#ifndef GL_PROGRAM_H
#define GL_PROGRAM_H

#include <GL/glew.h>
#include <SDL_opengl.h>

#include <unordered_map>
#include <string>

#include "GLShader.h"

namespace Coasters {
namespace Graphics {

class GLProgram {
public:
  GLProgram(const std::vector<GLShader> &shaders);
  ~GLProgram();
  GLuint resource() const { return program_; }

  GLint attribute(const std::string &attr) const {
    return glGetAttribLocation(program_, attr.c_str());
  }

  void uniform(const std::string &unif) {
    uniforms_[unif] = glGetUniformLocation(program_, unif.c_str());
  }

  void setUniform(const std::string &unif, float x, float y, float z) {
    glUniform3f(uniforms_[unif], x, y, z);
  }

  void setUniform(const std::string &unif, const GLfloat *value) {
    glUniformMatrix4fv(uniforms_[unif], 1, GL_FALSE, value);
  }

  void Use();
  bool IsInUse();
  void StopUsing();
private:
  GLuint program_;
  std::unordered_map<std::string, GLint> uniforms_;
};

} // Graphics
} // Coasters
#endif
