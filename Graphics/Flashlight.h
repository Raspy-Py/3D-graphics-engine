#pragma once
#include <string>
#include "Shader.h"
#include "LightSource.h"

class Shader;

class Flashlight : public LightSource
{
public:
	Flashlight(float linear, float quadratic, float cutOffAngle, 
			   glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, 
			   glm::vec3* position, glm::vec3* direction);
	void bufferData(const Shader* shader, int index = -1) const override;
};

