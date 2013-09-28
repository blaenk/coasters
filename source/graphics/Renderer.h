#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

namespace Coasters {
namespace Engine {
  class Engine;
  class Event; }
namespace Graphics {

class Mesh;

class Renderer {
public:
  virtual void Render() = 0;
  virtual void registerMesh(std::shared_ptr<Mesh> mesh) = 0;
};

} // Graphics
} // Coasters
#endif
