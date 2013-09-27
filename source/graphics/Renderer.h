#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

namespace Coasters {
namespace Engine {
  class Engine;
  class Event; }
namespace Graphics {

class Renderer {
public:
  virtual void Render() = 0;
  virtual void OnEvent(const Engine::Event& event) = 0;
protected:
  Engine::Engine *engine_;
};

} // Graphics
} // Coasters
#endif
