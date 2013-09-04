#ifndef RENDERER_H
#define RENDERER_H

namespace Coasters {
namespace Graphics {

class Renderer {
public:
  Renderer();
  ~Renderer();

  virtual void Render() = 0;
  virtual void ShutDown() = 0;
};

} // Graphics
} // Coasters
#endif
