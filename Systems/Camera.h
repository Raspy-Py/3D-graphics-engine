#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Window.h"


class Camera
{
public:
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 position;
	glm::mat4 rotation;

	float fov;
	Camera(glm::vec3 position, float fov);

	glm::mat4 getProjection();
	glm::mat4 getView();
	void rotate(float x, float y, float z);
private:
	void updateVectors();
};

