#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/constants.hpp>

namespace Coasters {
namespace Game {

Camera::Camera() :
  position_(1.2f, 1.2f, 1.2f), right_(1.0f, 0.0f, 0.0f),
  up_(0.0f, 0.0f, 1.0f), look_(0.0f, 0.0f, 0.0f) {
    this->view_ = glm::lookAt(position_, look_, up_);
    this->projection_ = glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 10.0f);
}

void Camera::setPosition(const glm::vec3& position) { this->position_ = position; }
void Camera::setLens(float fovY, float aspect, float znear, float zfar) {
  this->fovY_ = fovY;
  this->aspect_ = aspect;
  this->nearZ_ = znear;
  this->farZ_ = zfar;

  this->projection_ = glm::perspective(this->fovY_, this->aspect_, this->nearZ_, this->farZ_);
}

void Camera::lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up) {}

void Camera::strafe(float distance) {
  glm::vec3 s = glm::vec3(distance);
  glm::vec3 r = this->right_;
  glm::vec3 p = this->position_;
  this->position_ = (s * r) + p;
}

void Camera::walk(float distance) {
  glm::vec3 s = glm::vec3(distance);
  glm::vec3 l = this->look_;
  glm::vec3 p = this->position_;

  this->position_ = (s * l) + p;
}

void Camera::pitch(float angle) {
  glm::mat4 R = glm::rotate(angle, this->right_);
  glm::mat4 inverseTranspose = glm::transpose(glm::inverse(R));

  this->up_ = glm::vec3(inverseTranspose * glm::vec4(this->up_, 1.0f));
  this->look_ = glm::vec3(inverseTranspose * glm::vec4(this->look_, 1.0f));
}

void Camera::rotateY(float angle) {
  glm::mat4 R = glm::rotate(angle, 1.0f, 1.0f, 1.0f);
  glm::mat4 inverseTranspose = glm::transpose(glm::inverse(R));

  this->right_ = glm::vec3(inverseTranspose * glm::vec4(this->right_, 1.0f));
  this->up_ = glm::vec3(inverseTranspose * glm::vec4(this->up_, 1.0f));
  this->look_ = glm::vec3(inverseTranspose * glm::vec4(this->look_, 1.0f));
}

void Camera::updateViewMatrix() {}

glm::mat4 Camera::view() const { return this->view_; }
glm::mat4 Camera::projection() const { return this->projection_; }
glm::mat4 Camera::viewProjection() const {
  return this->projection_ * this->view_;
}

const glm::vec3& Camera::position() const { return this->position_; }
const glm::vec3& Camera::right() const { return this->right_; }
const glm::vec3& Camera::up() const { return this->up_; }
const glm::vec3& Camera::look() const { return this->look_; }

float Camera::nearZ() const { return this->nearZ_; }
float Camera::farZ() const { return this->farZ_; }
float Camera::aspect() const { return this->aspect_;}
float Camera::fovY() const { return this->fovY_; }
float Camera::fovX() const {
  float halfWidth = 0.5f * this->nearWindowWidth();
  return 2.0f * atan(halfWidth / this->nearZ_);
}

float Camera::nearWindowWidth() const { return this->aspect_ * this->nearWindowHeight_; }
float Camera::nearWindowHeight() const { return this->nearWindowHeight_; }
float Camera::farWindowWidth() const { return this->aspect_ * this->farWindowHeight_; }
float Camera::farWindowHeight() const { return this->farWindowHeight_; }

} // Game
} // Coasters
