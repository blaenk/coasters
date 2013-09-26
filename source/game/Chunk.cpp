#include "Chunk.h"

namespace Coasters {
namespace Game {

Chunk::Chunk(int x, int y, int z) : chunkDimensions_(std::make_tuple(x, y, z)) {
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
      this->mesh_.AddTriangle(A, B, C);
      this->mesh_.AddTriangle(C, D, A);
      break;
    case Facing::Back:
      this->mesh_.AddTriangle(G, F, E);
      this->mesh_.AddTriangle(E, H, G);
      break;
    case Facing::Up:
      this->mesh_.AddTriangle(G, H, C);
      this->mesh_.AddTriangle(C, H, D);
      break;
    case Facing::Down:
      this->mesh_.AddTriangle(B, F, A);
      this->mesh_.AddTriangle(A, F, E);
      break;
    case Facing::Left:
      this->mesh_.AddTriangle(E, A, H);
      this->mesh_.AddTriangle(H, A, D);
      break;
    case Facing::Right:
      this->mesh_.AddTriangle(F, G, B);
      this->mesh_.AddTriangle(B, G, C);
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
