#include "GLMesh.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ctime>
#include <cmath>

namespace Coasters {
namespace Graphics {

GLMesh::GLMesh(std::shared_ptr<Mesh> mesh) :
  vao_(0), vbo_(0), mesh_(mesh) {
  glGenVertexArrays(1, &vao_);
  glBindVertexArray(vao_);

  glGenBuffers(1, &vbo_);

  auto verts = this->mesh_->GetVertices();

  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), &verts[0], GL_STATIC_DRAW);
}

GLMesh::~GLMesh() {
  glDeleteBuffers(1, &vbo_);
  glDeleteVertexArrays(1, &vao_);
}

} // Graphics
} // Coasters
