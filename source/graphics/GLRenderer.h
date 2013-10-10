#ifndef GL_RENDERER_H
#define GL_RENDERER_H

#include <vector>
#include <memory>

// renderer
#include "Renderer.h"
#include "GLProgram.h"
#include "GLMesh.h"

namespace Coasters {
namespace Graphics {

class GLRenderer : public Renderer {
public:
  GLRenderer();
  ~GLRenderer();

  bool Initialize();
  void Render() override;

  void registerMesh(std::shared_ptr<Graphics::Mesh> mesh);
  void registerView(std::shared_ptr<glm::mat4> view);
  void registerProjection(std::shared_ptr<glm::mat4> projection);

private:
  std::shared_ptr<GLProgram> program_;
  std::vector<std::shared_ptr<GLMesh>> meshes_;

  std::shared_ptr<glm::mat4> view_;
  std::shared_ptr<glm::mat4> projection_;

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
