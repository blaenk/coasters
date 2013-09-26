#ifndef ACTOR_COMPONENT_H
#define ACTOR_COMPONENT_H

#include <memory>
#include <string>

namespace Coasters {
namespace Game {

class Actor;

class ActorComponent {
public:
  ActorComponent();
  virtual ~ActorComponent();

  virtual bool Initialize() = 0;
  virtual void PostInitialize() = 0;
  virtual void Update(int delta) = 0;

  virtual std::string GetName() const = 0;

private:
  std::weak_ptr<Actor> actor_;
};

} // Game
} // Coasters

#endif
