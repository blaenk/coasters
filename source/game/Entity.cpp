#include "Entity.h"

#include <memory>

namespace Coasters {
namespace Game {

Entity::Entity() {}
Entity::~Entity() {}

void Entity::AddComponent(const std::string &name, std::shared_ptr<EntityComponent> component) {
  components_[name] = component;
}

} // Game
} // Coasters
