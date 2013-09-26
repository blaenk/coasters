#include "MeshComponent.h"

namespace Coasters {
namespace Game {

MeshComponent::MeshComponent() :
  triangleCount_(0) {
}

bool MeshComponent::Initialize() {
  return true;
}
void MeshComponent::PostInitialize() {}
void MeshComponent::Update(int delta) {}

std::string MeshComponent::GetName() const { return "Mesh"; }

void MeshComponent::AddTriangle(const glm::vec3 v1, const glm::vec3 v2, const glm::vec3 v3) {
  this->vertices_.push_back(v1);
  this->vertices_.push_back(v2);
  this->vertices_.push_back(v3);
  this->triangleCount_++;
}

int MeshComponent::GetTriangleCount() const {
  return this->triangleCount_;
}

const std::vector<glm::vec3>& MeshComponent::GetVertices() const {
  return this->vertices_;
}

} // Game
}
