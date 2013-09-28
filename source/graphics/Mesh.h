#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>

namespace Coasters {
namespace Graphics {

class Mesh {
public:
  Mesh();
  ~Mesh();

  void AddTriangle(const glm::vec3 v1, const glm::vec3 v2, const glm::vec3 v3);

  int GetTriangleCount() const;
  const std::vector<glm::vec3>& GetVertices() const;
private:
  int triangleCount_;
  std::vector<glm::vec3> vertices_;
};

} // Graphics
} // Coasters
#endif
