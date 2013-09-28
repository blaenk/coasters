#include "Chunk.h"

#include "MeshComponent.h"
#include "graphics/Mesh.h"

namespace Coasters {
namespace Game {

Chunk::Chunk(int x, int y, int z) :
  chunkDimensions_(std::make_tuple(x, y, z)) {
  auto mesh = std::make_shared<MeshComponent>();
  mesh->Initialize();
  this->AddComponent("mesh", mesh);
}

std::string Chunk::GetName() const { return "Chunk"; }

bool Chunk::isValidCoordinate(BlockCoordinate &coordinate) {
  int x, dx, y, dy, z, dz;
  std::tie(x, y, z) = coordinate;
  std::tie(dx, dy, dz) = this->chunkDimensions_;

  return x > 0 && x < dx &&
         y > 0 && y < dy &&
         z > 0 && z < dz;
}

void Chunk::Fill() {
  //int dim = std::get<1>(this->chunkDimensions_);
  float dim = 0.5f;
  this->AddFace(std::make_tuple(0, 0, 0), Facing::Left, dim);
  this->AddFace(std::make_tuple(0, 0, 0), Facing::Right, dim);
  this->AddFace(std::make_tuple(0, 0, 0), Facing::Up, dim);
  this->AddFace(std::make_tuple(0, 0, 0), Facing::Down, dim);
  this->AddFace(std::make_tuple(0, 0, 0), Facing::Back, dim);
  this->AddFace(std::make_tuple(0, 0, 0), Facing::Front, dim);

  auto mesh_component = this->GetComponent<MeshComponent>("mesh").lock();

  if (mesh_component) mesh_component->Submit();
}

bool Chunk::SetBlock(BlockCoordinate &coord, BlockType type) {
  if (!isValidCoordinate(coord)) return false;

  this->blocks_[coord] = type;
  return true;
}

void Chunk::RemoveBlock(BlockCoordinate &coord) {
  auto it = this->blocks_.find(coord);

  if (it != this->blocks_.end())
    this->blocks_.erase(it);
}

void Chunk::AddFace(BlockCoordinate &coord, Facing facing, float size) {
  int x, y, z;
  std::tie(x, y, z) = coord;
  auto mesh_component = this->GetComponent<MeshComponent>("mesh").lock();

  if (!mesh_component) return;

  auto mesh = mesh_component->GetMesh();

  float xend = x + size, yend = y + size, zend = z + size;

  // front face
  glm::vec3 A(x, y, zend);
  glm::vec3 B(xend, y, zend);
  glm::vec3 C(xend, yend, zend);
  glm::vec3 D(x, yend, zend);

  // back face
  glm::vec3 E(x, y, z);
  glm::vec3 F(xend, y, z);
  glm::vec3 G(xend, yend, z);
  glm::vec3 H(x, yend, z);

  switch (facing) {
    case Facing::Front:
      mesh->AddTriangle(A, B, C);
      mesh->AddTriangle(C, D, A);
      break;
    case Facing::Back:
      mesh->AddTriangle(G, F, E);
      mesh->AddTriangle(E, H, G);
      break;
    case Facing::Up:
      mesh->AddTriangle(G, H, C);
      mesh->AddTriangle(C, H, D);
      break;
    case Facing::Down:
      mesh->AddTriangle(B, F, A);
      mesh->AddTriangle(A, F, E);
      break;
    case Facing::Left:
      mesh->AddTriangle(E, A, H);
      mesh->AddTriangle(H, A, D);
      break;
    case Facing::Right:
      mesh->AddTriangle(F, G, B);
      mesh->AddTriangle(B, G, C);
      break;
  }
}

void Chunk::BuildMesh() {
  for (const auto &block : this->blocks_) {
    printf("%d", block.second);
  }
}

} // Game
} // Coasters
