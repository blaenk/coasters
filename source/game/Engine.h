#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <memory>
#include <unordered_map>

namespace Coasters {
namespace Game {

class EngineComponent;

class Engine {
public:
  // Visual Studio 2012 still doesn't support template aliases
  // http://msdn.microsoft.com/en-us/library/vstudio/hh567368.aspx
  // using ComponentsType = std::unordered_map<std::string, std::shared_ptr<ActorComponent>>;
  typedef std::unordered_map<std::string, std::shared_ptr<EngineComponent>> ComponentsType;

  static Engine *Instance();
  bool Initialize();

  void AddComponent(std::string name, EngineComponent *component);

  template <class ComponentType>
  std::weak_ptr<ComponentType> GetComponent(std::string name);

protected:
  Engine();
  ~Engine();

private:
  static Engine *instance_;
  std::unordered_map<std::string, EngineComponent *> components_;
};

template <class ComponentType>
std::weak_ptr<ComponentType> Engine::GetComponent(std::string name) {
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