#include "Input.h"

#include "engine/Engine.h"

namespace Coasters {
namespace Input {

Input::Input() {}

void Input::feedEvent(SDL_Event event) {
  for (auto handler : keyHandlers_[event.key.keysym.sym])
    handler();
}

void Input::Bind(SDL_Keycode key, std::function<void ()> func) {
  keyHandlers_[key].push_back(func);
}

} // Input
} // Coasters
