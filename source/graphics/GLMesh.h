#ifndef GL_MESH_H
#define GL_MESH_H

#include <GL/glew.h>
#include <SDL_opengl.h>

#include <memory>

#include "GLProgram.h"

#include "Mesh.h"

namespace Coasters {
namespace Graphics {

class GLMesh {
public:
  GLMesh(std::shared_ptr<Mesh> mesh, std::shared_ptr<GLProgram> program);
  void Bind();
  void Unbind();
  ~GLMesh();
  GLsizei vertCount() const {
    return static_cast<GLsizei>(mesh_->GetVertices().size());
  }
private:
  GLuint vao_;
  GLuint vbo_;

  std::shared_ptr<Mesh> mesh_;
};

} // Graphics
} // Coasters
#endif
