#ifndef ENGINE_H
#define ENGINE_H

// includes
#include <string>
#include <memory>
#include <unordered_map>

#include "platform/Application.h"

// events
#include "Event.h"

// components
#include "input/Input.h"
#include "graphics/GLRenderer.h"
#include "game/Game.h"

namespace Coasters {
namespace Engine {

class Engine {
public:
  Engine(Platform::Application *application);

  void Engine::Initialize();
  void RunFrame(float lag);
  void OnEvent(const Event &event);

private:
  Graphics::GLRenderer renderer_;
  Game::Game game_;
  Input::Input input_;
  Platform::Application *application_;
};

} // Engine
} // Coasters

#endif
