#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

namespace Coasters {
namespace Game {

class Camera {
public:
  Camera();

  void setPosition(const glm::vec3& position);
  void setLens(float fovY, float aspect, float znear, float zfar);
  void lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up);

  void strafe(float distance);
  void walk(float distance);
  void pitch(float angle);
  void rotateY(float angle);
  void updateViewMatrix();

  // getters
  glm::mat4 view() const;
  glm::mat4 projection() const;
  glm::mat4 viewProjection() const;

  const glm::vec3& position() const;
  const glm::vec3& right() const;
  const glm::vec3& up() const;
  const glm::vec3& look() const;

  float nearZ() const;
  float farZ() const;
  float aspect() const;
  float fovY() const;
  float fovX() const;

  float nearWindowWidth() const;
  float nearWindowHeight() const;
  float farWindowWidth() const;
  float farWindowHeight() const;

private:
  glm::vec3 position_;
  glm::vec3 right_;
  glm::vec3 up_;
  glm::vec3 look_;

  float nearZ_;
  float farZ_;
  float aspect_;
  float fovY_;
  float nearWindowHeight_;
  float farWindowHeight_;

  glm::mat4 view_;
  glm::mat4 projection_;
};

/* opengl
  float fov() const;
  void setFOV(float fieldOfView);

  float nearPlane() const;
  float farPlane() const;

  void setNearAndFarPlanes(float nearPlane, float farPlane);

  glm::mat4 orientation() const;
  void offsetOrientation(float upAngle, float rightAngle);

  void lookAt(glm::vec3 position);

  float aspectRatio() const;
  void setAspectRatio(float aspectRatio);

  glm::vec3 forward() const;
  glm::vec3 right() const;
  glm::vec3 up() const;

  glm::mat4 viewProjection() const;
  glm::mat4 projection() const;
  glm::mat4 view() const;

private:
  glm::vec3 position_;
  float horizontalAngle_;
  float verticalAngle_;
  float fov_;
  float nearPlane_;
  float farPlane_;
  float aspectRatio_;
};*/

} // Game
} // Coasters

#endif
