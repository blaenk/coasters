#ifndef ENTITY_H
#define ENTITY_H

#include "EntityComponent.h"

#include <string>
#include <memory>
#include <unordered_map>

namespace Coasters {
namespace Game {

class Entity {
public:
  typedef std::unordered_map<std::string, std::shared_ptr<EntityComponent>> ComponentsType;

  Entity();
  ~Entity();

  void AddComponent(const std::string &name, std::shared_ptr<EntityComponent> component);
  virtual std::string GetName() const = 0;

  void Update(int delta);

  template <class ComponentType>
  std::weak_ptr<ComponentType> GetComponent(const std::string &name) {
    auto search = components_.find(name);

    if (search != components_.end()) {
      return std::weak_ptr<ComponentType>(std::static_pointer_cast<ComponentType>(search->second));
    } else {
      return std::weak_ptr<ComponentType>();
    }
  }

private:
  ComponentsType components_;
};

} // Game
} // Coasters

#endif
