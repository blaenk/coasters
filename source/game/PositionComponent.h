#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include <memory>
#include <string>

#include <glm/glm.hpp>

#include "EntityComponent.h"

namespace Coasters {
namespace Game {

class PositionComponent : public EntityComponent {
public:
  PositionComponent(int x, int y, int z) : position_(std::make_shared<glm::vec3>(x, y, z)) {}

  // INTERFACE
  bool Initialize() override;
  void PostInitialize() override;
  void Update(int delta) override;

  std::shared_ptr<glm::vec3> position() {
    return position_;
  }

  void setPosition(std::shared_ptr<glm::vec3> position) {
    position_ = position;
  }

  std::string GetName() const override { return "Position"; };
private:
  std::shared_ptr<glm::vec3> position_;
};

} // Game
} // Coasters

#endif
