#include "LightSource.h"

LightSource::LightSource()
{
	position = nullptr;
	direction = nullptr;

	ambient = glm::vec3(0.0f);
	diffuse = glm::vec3(0.0f);
	specular = glm::vec3(0.0f);

	constant = 1.0;
	linear = 0.0f;
	quadratic = 0.0f;
	cutOff = 0.0f;
}
