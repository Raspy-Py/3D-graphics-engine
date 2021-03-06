#include "Camera.h"

Camera::Camera(glm::vec3 position, float fov)
{
	this->position = position;
	this->fov = fov;
	this->rotation = glm::mat4(1.0f);
	updateVectors();
}

glm::mat4 Camera::getProjection()
{
	float ar = (float)Window::width / (float)Window::height;
	return glm::perspective(glm::radians(fov), ar, 0.1f, 100.0f);
}

glm::mat4 Camera::getView()
{
	return glm::lookAt(position, position + front, up);
}

void Camera::rotate(float x, float y, float z)
{
	rotation = glm::rotate(rotation, z, glm::vec3(0, 0, 1));
	rotation = glm::rotate(rotation, y, glm::vec3(0, 1, 0));
	rotation = glm::rotate(rotation, x, glm::vec3(1, 0, 0));

	updateVectors();
}

void Camera::updateVectors()
{
	front = glm::vec3(rotation * glm::vec4(0, 0, -1, 1));
	right = glm::vec3(rotation * glm::vec4(1,0,0,1));
	up = glm::vec3(rotation * glm::vec4(0, 1, 0, 1));
}
