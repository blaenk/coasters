#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include "Event.h"

namespace Coasters {
namespace Engine {

class InputEvent : public Event {
public:
  static enum class Subject : uint8_t {
  };

  InputEvent(Subject subject) :
    Event(Event::Scope::Input),
    subject_(subject) {}

  Subject subject() const { return this->subject_; }

private:
  Subject subject_;
};

} // Engine
} // Coasters

#endif
