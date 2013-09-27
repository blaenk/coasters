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
  // Visual Studio 2012 still doesn't support template aliases
  // http://msdn.microsoft.com/en-us/library/vstudio/hh567368.aspx
  // using ComponentsType = std::unordered_map<std::string, std::shared_ptr<EntityComponent>>;
  typedef std::unordered_map<std::string, std::shared_ptr<EntityComponent>> ComponentsType;

  Entity();
  ~Entity();

  void AddComponent(std::string name, EntityComponent *component);
  virtual std::string GetName() const = 0;

  void Update(int delta);

  template <class ComponentType>
  std::weak_ptr<ComponentType> GetComponent(std::string name);

private:
  ComponentsType components_;
};

template <class ComponentType>
std::weak_ptr<ComponentType> Entity::GetComponent(std::string name) {
  ComponentsType::iterator search = components_.find(name);

  if (search != components_.end()) {
    return std::weak_ptr<ComponentType>(std::static_pointer_cast<ComponentType>(search->second));
  } else {
    return std::weak_ptr<ComponentType>();
  }
}

} // Game
} // Coasters

#endif
