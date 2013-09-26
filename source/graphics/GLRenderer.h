#ifndef GL_RENDERER_H
#define GL_RENDERER_H

// #includes
#include <GL/glew.h>
#include <SDL_opengl.h>

// renderer
#include "Renderer.h"

#include "engine/RendererEvent.h"

#include "game/Camera.h"
#include "game/Chunk.h"

namespace Coasters {
namespace Graphics {

class GLRenderer : public Renderer {
public:
  GLRenderer();
  ~GLRenderer();

  bool Initialize();
  void Render() override;
  void OnEvent(std::shared_ptr<Engine::RendererEvent> event) override;

private:
  Game::Chunk chunk_;
  Game::Camera camera_;

  GLuint vao;
  GLuint vbo;
  GLint uniColor;
  GLint uniCamera;
  GLuint shaderProgram;
  GLuint fragmentShader;
  GLuint vertexShader;
};

} // Graphics
} // Coasters
#endif
