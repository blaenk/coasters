#include "Game.h"

#include <tuple>
#include <cmath>

#include "engine/Engine.h"

namespace Coasters {
namespace Game {

Game::Game(double fps) :
  updateInterval_(1 / fps) {
}

void Game::Initialize() {
  auto chunk = std::make_shared<Chunk>(16, 16, 16);
  chunk->Fill();
  entities_.push_back(chunk);
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
