#include "Input.h"

#include "engine/Engine.h"

namespace Coasters {
namespace Input {

// SDL_Event is a tagged union on .type
void Input::feedEvent(SDL_Event event) {
  if (event.type != SDL_KEYDOWN)
    return;

  auto handlers = keyHandlers_.find(event.key.keysym.sym);

  if (handlers == keyHandlers_.end()) {
    return;
  }

  for (auto handler : handlers->second)
    handler();
}

void Input::Bind(SDL_Keycode key, std::function<void ()> func) {
  keyHandlers_[key].push_back(func);
}

} // Input
} // Coasters
