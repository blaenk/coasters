#ifndef GL_SHADER_H
#define GL_SHADER_H

#include <GL/glew.h>
#include <SDL_opengl.h>
#include <string>

namespace Coasters {
namespace Graphics {

class GLShader {
public:
  GLShader(GLenum type, const std::string &source);
  ~GLShader();

  GLuint resource() const {
    return shader_;
  }
private:
  GLenum type_;
  GLuint shader_;
};

} // Graphics
} // Coasters
#endif
