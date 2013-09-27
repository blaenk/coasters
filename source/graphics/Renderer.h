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
  virtual void SetEngine(Engine::Engine *engine) final {
    engine_ = engine;
  }
protected:
  Engine::Engine *engine_;
};

} // Graphics
} // Coasters
#endif
