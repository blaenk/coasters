#ifndef ACTOR_H
#define ACTOR_H

#include "ActorComponent.h"

#include <string>
#include <memory>
#include <unordered_map>

namespace Coasters {
namespace Game {

class Actor {
public:
  // Visual Studio 2012 still doesn't support template aliases
  // http://msdn.microsoft.com/en-us/library/vstudio/hh567368.aspx
  // using ComponentsType = std::unordered_map<std::string, std::shared_ptr<ActorComponent>>;
  typedef std::unordered_map<std::string, std::shared_ptr<ActorComponent>> ComponentsType;

  Actor();
  ~Actor();

  void AddComponent(std::string name, ActorComponent *component);
  virtual std::string GetName() const = 0;

  void Update(int delta);

  template <class ComponentType>
  std::weak_ptr<ComponentType> GetComponent(std::string name);

private:
  ComponentsType components_;
};

template <class ComponentType>
std::weak_ptr<ComponentType> Actor::GetComponent(std::string name) {
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