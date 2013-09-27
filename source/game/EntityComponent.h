#ifndef ENTITY_COMPONENT_H
#define ENTITY_COMPONENT_H

#include <memory>
#include <string>

namespace Coasters {
namespace Game {

class Entity;

class EntityComponent {
public:
  EntityComponent();
  virtual ~EntityComponent();

  virtual bool Initialize() = 0;
  virtual void PostInitialize() = 0;
  virtual void Update(int delta) = 0;

  virtual std::string GetName() const = 0;

private:
  std::weak_ptr<Entity> entity_;
};

} // Game
} // Coasters

#endif
