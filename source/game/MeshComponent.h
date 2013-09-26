#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include <memory>
#include <string>
#include <vector>
#include <glm/glm.hpp>

#include "ActorComponent.h"

namespace Coasters {
namespace Game {

class MeshComponent : public ActorComponent {
public:
  MeshComponent();

  // INTERFACE
  bool Initialize() override;
  void PostInitialize() override;
  void Update(int delta) override;

  std::string GetName() const override;

  // CHILD
  void AddTriangle(const glm::vec3 v1, const glm::vec3 v2, const glm::vec3 v3);

  int GetTriangleCount() const;
  const std::vector<glm::vec3>& GetVertices() const;
private:
  int triangleCount_;
  std::vector<glm::vec3> vertices_;
};

} // Game
} // Coasters

#endif
