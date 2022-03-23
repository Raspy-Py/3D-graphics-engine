#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"

class Shader;


class LightSource
{
public:
	LightSource();
	virtual void bufferData(const Shader* shader, int index = -1) const = 0;
protected:
	glm::vec3* position;
	glm::vec3* direction;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

	float constant;
	float linear;
	float quadratic;
	float cutOff;
	float outterCutOff;
};

