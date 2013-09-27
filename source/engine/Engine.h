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

/*
class RenderService {
public:
  RenderService(Graphics::Renderer *renderer) :
    renderer_(renderer) {}

  void registerMesh(Graphics::Mesh *mesh) {
    renderer->registerMesh(mesh);
  }
private:
  Graphics::Renderer *renderer_;
};
*/

class Engine {
public:
  Engine();

  void SetApplication(Platform::Application *application) {
    application_ = application;
  }

  void Initialize();
  void RunFrame(double lag);
  void OnEvent(const Event &event);

  // RenderService renderService() { return renderService_; }
  // GameService gameService() { return gameService_; }
  // InputService inputService() { return inputService_; }

private:
  Graphics::GLRenderer renderer_;
  // RenderService renderService_;

  Game::Game game_;
  // GameService gameService_;

  Input::Input input_;
  // InputService inputService_;

  Platform::Application *application_;
};

} // Engine
} // Coasters

#endif
