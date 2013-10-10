#include "Entity.h"

#include <memory>

namespace Coasters {
namespace Game {

Entity::~Entity() {}

void Entity::AddComponent(const std::string &name, std::shared_ptr<EntityComponent> component) {
  component->setParent(this);
  component->Initialize();
  components_[name] = component;
}

} // Game
} // Coasters
