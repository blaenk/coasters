#include "Engine.h"

#include <assert.h>

namespace Coasters {
namespace Engine {

namespace Services {
  RendererService *rendererService = nullptr;
}

Engine::Engine() :
  renderer_(),
  game_(120) {}

void Engine::Initialize() {
  bool res = this->renderer_.Initialize();
  Services::rendererService = new RendererService(&renderer_);
  this->game_.Initialize();
}

// void Engine::FeedInput(SDL_Event event) {
//   this->input_.Feed();
// }

double Engine::RunFrame(double lag) {
  //this->input_.Poll();
    // input_.events is queue of key events
  //this->game_.Update(lag, this->input_.events());
    // meshcomponent: renderer->addMesh(this);
  //this->renderer_.Render(this->game_.actors());
    // renderer_.meshes are rendered

  this->input_.Poll();
  double unconsumed = this->game_.Update(lag);
  this->renderer_.Render();
  return unconsumed;
}

} // Engine
} // Coasters
