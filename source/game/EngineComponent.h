#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

#include <string>

namespace Coasters {
namespace Game {

class EngineComponent {
public:
  EngineComponent();
  ~EngineComponent();

  virtual std::string GetName() const = 0;
};

} // Game
} // Coasters

#endif