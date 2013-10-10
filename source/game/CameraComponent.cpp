#include "CameraComponent.h"

#include "engine/Engine.h"
#include "PositionComponent.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/constants.hpp>

namespace Coasters {
namespace Game {

CameraComponent::CameraComponent() :
  right_(1.0f, 0.0f, 0.0f), up_(0.0f, 0.0f, 1.0f), look_(0.0f, 0.0f, 0.0f) {
}

void CameraComponent::moveForward() {
  printf("W pressed\n");
  auto position = parent()->GetComponent<PositionComponent>("position").lock();

  if (position) {
    position->setPosition(std::make_shared<glm::vec3>(*position->position() - glm::vec3(1.0f, 0.0f, 0.0f)));
    // position = std::make_shared<glm::vec3>(position - position());
    Initialize();
  }
}

const glm::vec3 CameraComponent::position() const {
  auto position = parent()->GetComponent<PositionComponent>("position").lock();

  if (position) {
    printf("found position\n");
    return *position->position().get();
  }
  else
    return glm::vec3(1.2f, 1.2f, 1.2f);
}

bool CameraComponent::Initialize() {
  this->view_ = std::make_shared<glm::mat4>(glm::lookAt(position(), look_, up_));
  this->projection_ = std::make_shared<glm::mat4>(glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 10.0f));
  this->Submit();
  return true;
}

void CameraComponent::Submit() {
  Engine::Services::rendererService->registerView(view_);
  Engine::Services::rendererService->registerProjection(projection_);
}

void CameraComponent::PostInitialize() {}
void CameraComponent::Update(int delta) {}

} // Game
}
