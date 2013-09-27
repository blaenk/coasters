#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <SDL.h>

#include "engine/GameEvent.h"
#include "Chunk.h"

namespace Coasters {
namespace Engine { class Engine; }
namespace Game {

class Game {
public:
  Game(double interval);

  void SetEngine(Engine::Engine *engine) {
    engine_ = engine;
  }

  void Update(double lag);
  double UpdateInterval();

  void OnEvent(const Engine::Event& event);
private:
  void Update();

private:
  Engine::Engine *engine_;
  enum class Action : uint8_t {
    Forward,
    Backward,
    Left,
    Right
  };

  double updateInterval_;
  std::unordered_map<Engine::GameEvent::Subject,
                     std::vector<std::shared_ptr<Entity>>> handlers_;
  std::unordered_map<Action, SDL_Keysym> keyBinds_;
  std::unordered_map<Action,
                     std::vector<std::shared_ptr<EntityComponent>>> inputHandlers_;
};

} // Game
} // Coasters

#endif
