#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include "Event.h"

namespace Coasters {
namespace Engine {

class GameEvent : public Event {
public:
  static enum class Subject : uint8_t {
    ActorDestroyed
  };

  GameEvent(Subject subject) :
    Event(Event::Scope::Game),
    subject_(subject) {}

  Subject subject() const { return this->subject_; }

  ~GameEvent() {}

private:
  Subject subject_;
};

} // Engine
} // Coasters

#endif
