#ifndef GL_RENDERER_H
#define GL_RENDERER_H

#include <vector>
#include <memory>

// renderer
#include "Renderer.h"
#include "GLProgram.h"
#include "GLMesh.h"

#include "game/Camera.h"

namespace Coasters {
namespace Graphics {

class GLRenderer : public Renderer {
public:
  GLRenderer();
  ~GLRenderer();

  bool Initialize();
  void Render() override;

  void registerMesh(std::shared_ptr<Graphics::Mesh> mesh);

private:
  Game::Camera camera_;

  std::shared_ptr<GLProgram> program_;
  std::vector<std::shared_ptr<GLMesh>> meshes_;

  GLint fragmentShader;
  GLint vertexShader;
  GLint shaderProgram;
  GLint uniColor;
  GLint uniCamera;
  GLuint vao;
  GLuint vbo;
};

} // Graphics
} // Coasters
#endif
