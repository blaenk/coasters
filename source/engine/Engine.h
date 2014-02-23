#ifndef ENGINE_H
#define ENGINE_H

// includes
#include <SDL.h>
#include <string>
#include <memory>
#include <unordered_map>

// components
#include "input/Input.h"
#include "graphics/GLRenderer.h"
#include "game/Game.h"

namespace Coasters {
namespace Engine {

namespace Services {
  extern Graphics::Renderer *renderer;
  extern Input::Input *input;
} // services

class Engine {
public:
  Engine();

  void Initialize();
  double RunFrame(double lag);

private:
  Graphics::GLRenderer renderer_;
  Game::Game game_;
  Input::Input input_;
};

} // Engine
} // Coasters

#endif
