#include "Input.h"

#include "engine/Engine.h"
#include <SDL.h>

#include "engine/ApplicationEvent.h"

namespace Coasters {
namespace Input {

Input::Input(Engine::Engine *engine) :
  engine_(engine) {}

void Input::OnEvent(const Engine::Event &event) {
}

void Input::Poll() {
  using namespace Engine;
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      this->OnEvent(ApplicationEvent(ApplicationEvent::Subject::Quit));
      return;
    }

    if (event.type == SDL_KEYUP) {
      switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          this->engine_->OnEvent(ApplicationEvent(ApplicationEvent::Subject::Quit));
          break;
        case SDLK_f:
          this->engine_->OnEvent(ApplicationEvent(ApplicationEvent::Subject::FullscreenToggle));
          break;
        case SDLK_b:
          this->engine_->OnEvent(ApplicationEvent(ApplicationEvent::Subject::BorderToggle));
          break;
      }
    }
  }
}

} // Input
} // Coasters
