#ifndef APPLICATION_EVENT_H
#define APPLICATION_EVENT_H

#include "Event.h"

namespace Coasters {
namespace Engine {

class ApplicationEvent : public Event {
public:
  static enum class Subject : uint8_t {
    FullscreenToggle,
    BorderToggle,
    Quit
  };

  ApplicationEvent(Subject subject) :
    Event(Event::Scope::Application),
    subject_(subject) {}

  Subject subject() const { return this->subject_; }

private:
  Subject subject_;
};

} // Engine
} // Coasters

#endif
