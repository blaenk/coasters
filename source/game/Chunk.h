#ifndef CHUNK_H
#define CHUNK_H

#include <glm/glm.hpp>
#include <unordered_map>
#include <tuple>

#include "Actor.h"
#include "MeshComponent.h"

namespace std {
  template<>
  struct hash<std::tuple<int, int, int>> {
  public:
    // TODO: This won't work! xor is associative
    //       So coord (1, 2, 3) will hash the same as coord (3, 2, 1)
    std::size_t operator()(const std::tuple<int, int, int> &coords) const {
      int x, y, z;
      std::tie(x, y, z) = coords;
      return ((51 + x) * 51 + y) * 51 + z;;
    }
  };
}

namespace Coasters {
namespace Game {

class Chunk : public Actor {
public:
  typedef std::tuple<int, int, int> BlockCoordinate;
  typedef std::tuple<int, int, int> ChunkDimensions;
  enum class Facing : uint8_t {
    Up,
    Down,
    Left,
    Right,
    Front,
    Back
  };
  enum class BlockType : uint8_t {
    Grass,
    Dirt
  };

  Chunk(int x, int y, int z);

  virtual std::string GetName() const override;

  bool SetBlock(BlockCoordinate &coord, BlockType type);
  void RemoveBlock(BlockCoordinate &coord);

  void Fill();
  void BuildMesh();
  MeshComponent mesh_;

private:
  inline bool isValidCoordinate(BlockCoordinate &coordinate);
  void AddFace(BlockCoordinate &coord, Facing facing, float size);

private:
  glm::vec3 position_;
  ChunkDimensions chunkDimensions_;
  std::unordered_map<BlockCoordinate, BlockType> blocks_;
};

} // Game
} // Coasters

#endif
