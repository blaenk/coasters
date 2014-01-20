#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include <memory>
#include <string>

#include <glm/glm.hpp>

#include "EntityComponent.h"

namespace Coasters {
namespace Game {

class CameraComponent : public EntityComponent {
public:
  CameraComponent();

  // INTERFACE
  bool Initialize() override;
  void Submit();
  void PostInitialize() override;
  void Update(int delta) override;

  virtual std::string GetName() const { return "Camera"; }

  // getters
  const glm::vec3 position() const;
  const glm::vec3& right() const;
  const glm::vec3& up() const;
  const glm::vec3& look() const;

  void moveForward();

  std::shared_ptr<glm::mat4> projection() {
    return projection_;
  }

  void setProjection(std::shared_ptr<glm::mat4> projection) {
    projection_ = projection;
  }

  std::shared_ptr<glm::mat4> view() {
    return view_;
  }

  void setView(std::shared_ptr<glm::mat4> view) {
    view_ = view;
  }
private:
  std::shared_ptr<glm::mat4> view_;
  std::shared_ptr<glm::mat4> projection_;

  glm::vec3 right_;
  glm::vec3 up_;
  glm::vec3 look_;
};

} // Game
} // Coasters

#endif
