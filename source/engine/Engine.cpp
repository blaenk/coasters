#include "Engine.h"

#include <assert.h>

#include "RendererEvent.h"
#include "InputEvent.h"
#include "GameEvent.h"
#include "ApplicationEvent.h"

namespace Coasters {
namespace Engine {

Engine::Engine(Platform::Application *application) :
  game_(this, 120),
  renderer_(this),
  input_(this),
  application_(application) {}

void Engine::Initialize() {
  bool res = this->renderer_.Initialize();
}

void ProcessEvents() {}

void Engine::RunFrame(float lag) {
  //this->input_.Poll();
    // input_.events is queue of key events
  //this->game_.Update(lag, this->input_.events());
    // meshcomponent: renderer->addMesh(this);
  //this->renderer_.Render(this->game_.actors());
    // renderer_.meshes are rendered

  this->input_.Poll();
  this->game_.Update(lag);
  this->renderer_.Render();
}

// add Event::Scope::Application and forward to parent?
void Engine::OnEvent(const Event &event) {
  printf("engine event\n");

  switch (event.scope()) {
    case Event::Scope::Application:
      this->application_->OnEvent(event);
      break;
    case Event::Scope::Input:
      this->input_.OnEvent(event);
      break;
    case Event::Scope::Game:
      this->game_.OnEvent(event);
      break;
    case Event::Scope::Renderer:
      this->renderer_.OnEvent(event);
      break;
  }
}

} // Engine
} // Coasters
