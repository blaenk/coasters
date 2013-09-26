#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <memory>
#include <unordered_map>

#include "graphics/Renderer.h"

namespace Coasters {
namespace Engine {

class Event {
public:
  static enum class Scope : uint8_t {
    Audio,
    Game,
    Renderer
  };

  Scope scope() const { return this->scope_; }

  virtual ~Event();
private:
  Scope scope_;
};

} // Engine
} // Coasters

#endif
