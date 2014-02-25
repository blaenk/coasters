#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

// includes
#include <memory>
#include <unordered_map>
#include <vector>
#include <functional>

namespace Coasters {
namespace Engine { class Engine; }
namespace Input {

class Input {
public:
  void feedEvent(SDL_Event event);
  void Bind(SDL_Keycode key, std::function<void ()> func);
private:
  // vector of inputContexts?
  std::unordered_map<SDL_Keycode,
                     std::vector<std::function<void ()>>> keyHandlers_;
};

} // Input
} // Coasters

#endif
