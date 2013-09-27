#ifndef GL_RENDERER_H
#define GL_RENDERER_H

// #includes
#include <GL/glew.h>
#include <SDL_opengl.h>

// renderer
#include "Renderer.h"

#include "engine/Event.h"

#include "game/Camera.h"
#include "game/Chunk.h"

namespace Coasters {
namespace Graphics {

class GLRenderer : public Renderer {
public:
  GLRenderer(Engine::Engine *engine);
  ~GLRenderer();

  bool Initialize();
  void Render() override;
  void OnEvent(const Engine::Event& event) override;

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
