#include "Game.h"

#include <tuple>
#include <cmath>

#include "engine/Engine.h"

#include "PositionComponent.h"
#include "CameraComponent.h"
#include "InputComponent.h"

namespace Coasters {
namespace Game {

Game::Game(double fps) :
  updateInterval_(1 / fps) {
}

void Game::Initialize() {
  auto chunk = std::make_shared<Chunk>(16, 16, 16);
  chunk->Fill();
  entities_.push_back(chunk);

  auto player = std::make_shared<Entity>();

  auto position = std::make_shared<PositionComponent>(1.2f, 1.2f, 1.2f);
  player->AddComponent("position", position);

  auto camera = std::make_shared<CameraComponent>();
  player->AddComponent("camera", camera);

  auto input = std::make_shared<InputComponent>();
  input->Bind(SDLK_w, std::bind(&CameraComponent::moveForward, camera.get()));
  player->AddComponent("input", input);

  entities_.push_back(player);
}

double Game::Update(double lag) {
  while (lag >= this->updateInterval_) {
    this->Update();
    lag -= this->updateInterval_;
  }

  return lag;
}

void Game::Update() {}

double Game::UpdateInterval() {
  return this->updateInterval_;
}

} // Game
} // Coasters
