#include "Engine.h"

#include <assert.h>

namespace Coasters {
namespace Engine {

Engine::Engine() :
  game_(new Game::Game(120)),
  renderer_(new Graphics::GLRenderer) {
}

void Engine::Initialize() {
  bool res = this->renderer_->Initialize();
}

void Engine::Run(float lag) {
  this->game_->Update(lag);
  this->renderer_->Render();
}

void Engine::OnEvent(std::shared_ptr<Event> event) {
  switch (event->scope()) {
    case Event::Scope::Game:
      // this->game_->OnEvent(std::static_pointer_cast<GameEvent>(event));
      break;
    case Event::Scope::Renderer:
      this->renderer_->OnEvent(std::static_pointer_cast<RendererEvent>(event));
      break;
  }
}

} // Engine
} // Coasters
