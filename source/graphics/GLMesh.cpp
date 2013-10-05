#include "GLMesh.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ctime>
#include <cmath>

namespace Coasters {
namespace Graphics {

GLMesh::GLMesh(std::shared_ptr<Mesh> mesh, std::shared_ptr<GLProgram> program) :
  vao_(0), vbo_(0), mesh_(mesh) {
  glGenVertexArrays(1, &vao_);
  glBindVertexArray(vao_);

  glGenBuffers(1, &vbo_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);

  auto &verts = this->mesh_->GetVertices();

  printf("mesh has %d verts\n", verts.size());

  glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), &this->mesh_->GetVertices()[0], GL_STATIC_DRAW);
  printf("made mesh\n");

  GLuint pos = program->attribute("position");
  glEnableVertexAttribArray(pos);
  glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);

}

void GLMesh::Bind() {
  glBindVertexArray(vao_);
}

void GLMesh::Unbind() {
  glBindVertexArray(0);
}

GLMesh::~GLMesh() {
  printf("destroyed mesh!?\n");
  // glDeleteBuffers(1, &vbo_);
  // glDeleteVertexArrays(1, &vao_);
}

} // Graphics
} // Coasters
