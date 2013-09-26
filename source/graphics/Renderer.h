#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

namespace Coasters {
namespace Engine { class RendererEvent; }
namespace Graphics {

class Renderer {
public:
  virtual void Render() = 0;
  virtual void OnEvent(std::shared_ptr<Engine::RendererEvent> event) = 0;
};

} // Graphics
} // Coasters
#endif
