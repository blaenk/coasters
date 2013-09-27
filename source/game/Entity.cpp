#include "Entity.h"

#include <memory>

namespace Coasters {
namespace Game {

Entity::Entity() {}
Entity::~Entity() {}

void AddComponent(std::string name, EntityComponent *component) {}

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
