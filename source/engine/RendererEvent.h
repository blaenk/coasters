#ifndef RENDERER_EVENT_H
#define RENDERER_EVENT_H

#include "Event.h"

namespace Coasters {
namespace Engine {

class RendererEvent : public Event {
public:
  static enum class Subject : uint8_t {
    MeshAdded,
    MeshRemoved
  };

  RendererEvent(Subject subject) :
    Event(Event::Scope::Renderer),
    subject_(subject) {}

  Subject subject() const { return this->subject_; }

private:
  Subject subject_;
};

} // Engine
} // Coasters

#endif
