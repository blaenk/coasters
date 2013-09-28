#include "Mesh.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ctime>
#include <cmath>

namespace Coasters {
namespace Graphics {

Mesh::Mesh() :
  triangleCount_(0) {}

Mesh::~Mesh() {
}

void Mesh::AddTriangle(const glm::vec3 v1, const glm::vec3 v2, const glm::vec3 v3) {
  this->vertices_.push_back(v1);
  this->vertices_.push_back(v2);
  this->vertices_.push_back(v3);
  this->triangleCount_++;
}

int Mesh::GetTriangleCount() const {
  return this->triangleCount_;
}

const std::vector<glm::vec3>& Mesh::GetVertices() const {
  return this->vertices_;
}

} // Graphics
} // Coasters
