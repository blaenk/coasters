#include "Actor.h"

#include <memory>

namespace Coasters {
namespace Game {

Actor::Actor() {}
Actor::~Actor() {}

void AddComponent(std::string name, ActorComponent *component) {}

template <class ComponentType>
std::weak_ptr<ComponentType> GetComponent(std::string name) {
  auto component = this->components_.find(name);

  if (component == this->components_.end())
    return std::weak_ptr();
  else
    return std::weak_ptr(component->second);
}

} // Game
} // Coasters
