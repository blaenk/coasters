#ifndef GAME_H
#define GAME_H

#include <map>
#include <vector>
#include <SDL.h>

#include "Chunk.h"

namespace Coasters {
namespace Engine { class Engine; }
namespace Game {

class Game {
public:
  Game(double interval);

  void Initialize();

  double Update(double lag);
  double UpdateInterval();
private:
  void Update();

private:
  std::vector<std::shared_ptr<Entity>> entities_;
  enum class Action : uint8_t {
    Forward,
    Backward,
    Left,
    Right
  };

  double updateInterval_;
  std::map<Action, SDL_Keysym> keyBinds_;
  std::map<Action, std::vector<std::shared_ptr<EntityComponent>>> inputHandlers_;
};

} // Game
} // Coasters

#endif
