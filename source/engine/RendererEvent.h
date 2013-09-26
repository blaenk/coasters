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
    scope_(Event::Scope::Renderer),
    subject_(subject) {}

  Subject subject() const { return Subject::MeshAdded; }

private:
  Scope scope_;
  Subject subject_;
};

} // Engine
} // Coasters

#endif
