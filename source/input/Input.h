#ifndef INPUT_H
#define INPUT_H

// includes
#include <string>
#include <memory>
#include <unordered_map>

// events
#include "engine/Event.h"
#include "engine/InputEvent.h"

namespace Coasters {
namespace Engine { class Engine; }
namespace Input {

class Input {
public:
  Input(Engine::Engine *engine);

  void OnEvent(const Engine::Event &event);
  void Poll();

private:
  Engine::Engine *engine_;
};

} // Input
} // Coasters

#endif
