#ifndef VOXEL_H
#define VOXEL_H

#include "Actor.h"

namespace Coasters {
namespace Game {

class Voxel : public Actor {
public:
  Voxel();
  ~Voxel();

  virtual std::string GetName() const override;

private:
  // Position center;
  // std::array<Position, 8> vertices;
};

} // Game
} // Coasters

#endif
