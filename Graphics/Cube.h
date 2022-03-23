#pragma once
#include <glm/glm.hpp>
#include "Drawable.h"

class Cube : public Drawable
{
public:
	Cube(float size = 1.0f, glm::vec3 origin = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f));
	Cube(bool textured);
	~Cube();
private:
	void render(float size, glm::vec3, glm::vec3 color, bool textured);
};