#ifndef GAME_H
#define GAME_H

#include "Chunk.h"

namespace Coasters {
namespace Game {

class Game {
public:
  Game(double interval);

  void Update(double lag);
  double UpdateInterval();

private:
  void Update();

private:
  double updateInterval_;
};

} // Game
} // Coasters

#endif
