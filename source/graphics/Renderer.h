#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

#include <glm/glm.hpp>

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
  virtual void registerView(std::shared_ptr<glm::mat4> view) = 0;
  virtual void registerProjection(std::shared_ptr<glm::mat4> projection) = 0;
};

} // Graphics
} // Coasters
#endif
