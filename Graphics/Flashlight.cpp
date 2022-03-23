#include "Flashlight.h"

Flashlight::Flashlight(float linear, float quadratic, float cutOffAngle, 
					   glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, 
					   glm::vec3* position = nullptr, glm::vec3* direction = nullptr)
{
	this->constant = 1.0f;
	this->linear = linear;
	this->quadratic = quadratic;
	this->cutOff = cos(glm::radians(cutOffAngle - 2.5f));
	this->outterCutOff = cos(glm::radians(cutOffAngle + 2.5f));

	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;

	if (position != nullptr) this->position = position;
	else this->position = new glm::vec3(0.0f, 0.0f, 0.0f);
	if (direction != nullptr) this->direction = direction;
	else this->direction = new glm::vec3(1.0f, 0.0f, 0.0f);
}

void Flashlight::bufferData(const Shader* shader, int index) const
{
	std::string prefix = ((index != -1) ? "flashlight[" + std::to_string(index) + "]." : "spotLight.");

	shader->setFloat(prefix + "constant", constant);
	shader->setFloat(prefix + "linear", linear);
	shader->setFloat(prefix + "quadratic", quadratic);
	shader->setFloat(prefix + "cutOff", cutOff);
	shader->setFloat(prefix + "outterCutOff", outterCutOff);

	shader->setVec3(prefix + "direction", glm::value_ptr(*direction));
	shader->setVec3(prefix + "position", glm::value_ptr(*position));
	shader->setVec3(prefix + "ambient", glm::value_ptr(ambient));
	shader->setVec3(prefix + "diffuse", glm::value_ptr(diffuse));
	shader->setVec3(prefix + "specular", glm::value_ptr(specular));
}
