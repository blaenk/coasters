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
namespace Graphics { class Mesh; }
namespace Engine {

class RendererService {
public:
  RendererService(Graphics::Renderer *renderer) :
    renderer_(renderer) {}

  void registerMesh(std::shared_ptr<Graphics::Mesh> mesh) {
    renderer_->registerMesh(mesh);
  }
private:
  Graphics::Renderer *renderer_;
};

namespace Services {
  extern RendererService *rendererService;
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
