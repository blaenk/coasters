#ifndef ENGINE_H
#define ENGINE_H

// includes
#include <string>
#include <memory>
#include <unordered_map>

// events
#include "Event.h"
#include "RendererEvent.h"

// components
#include "graphics/GLRenderer.h"
#include "game/Game.h"

namespace Coasters {
namespace Engine {

class Engine {
public:
  Engine();

  void Engine::Initialize();
  void Run(float lag);
  void OnEvent(std::shared_ptr<Event> event);

private:
  std::unique_ptr<Coasters::Graphics::GLRenderer> renderer_;
  std::unique_ptr<Coasters::Game::Game> game_;
};

} // Engine
} // Coasters

#endif
