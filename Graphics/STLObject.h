#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "Drawable.h"


class STLObject : public Drawable
{
public:
	STLObject(const char* fileName);
private:
	glm::vec3 strToVec(std::string& line);
	std::vector<float> vBuffer;
};

