#ifndef GL_PROGRAM_H
#define GL_PROGRAM_H

#include <GL/glew.h>
#include <SDL_opengl.h>

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "GLShader.h"

namespace Coasters {
namespace Graphics {

class GLProgram {
public:
  GLProgram(const std::vector<std::shared_ptr<GLShader>> &shaders);
  ~GLProgram();
  GLuint resource() const { return program_; }

  GLint attribute(const std::string &attr) const {
    return glGetAttribLocation(program_, attr.c_str());
  }

  void uniform(const std::string &unif) {
    GLint val = glGetUniformLocation(program_, unif.c_str());
    printf("val for %s is %d\n", unif.c_str(), val);
    uniforms_[unif] = val;
  }

  void setUniform(const std::string &unif, float x, float y, float z) {
    glUniform3f(uniforms_[unif], x, y, z);
  }

  void setUniform(const std::string &unif, const glm::mat4 &value) {
    glUniformMatrix4fv(uniforms_[unif], 1, GL_FALSE, glm::value_ptr(value));
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
