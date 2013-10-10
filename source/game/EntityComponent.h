#ifndef ENTITY_COMPONENT_H
#define ENTITY_COMPONENT_H

#include <memory>
#include <string>

namespace Coasters {
namespace Game {

class Entity;

class EntityComponent {
public:
  EntityComponent() : parent_(nullptr) {}
  virtual ~EntityComponent();

  void setParent(Entity *parent) {
    parent_ = parent;
  }

  Entity *parent() const { return parent_; }

  virtual bool Initialize() = 0;
  virtual void PostInitialize() = 0;
  virtual void Update(int delta) = 0;

  virtual std::string GetName() const = 0;

private:
  Entity *parent_;
};

} // Game
} // Coasters

#endif
