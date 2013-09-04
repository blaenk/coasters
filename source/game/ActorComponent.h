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
  virtual void PostInitialize();
  virtual void Update(int delta);

  virtual std::string GetName() const = 0;

private:
  std::weak_ptr<Actor> actor_;
};

} // Game
} // Coasters

#endif