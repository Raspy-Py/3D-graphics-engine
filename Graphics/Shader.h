#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Drawable.h"
#include "LightSource.h"

class LightSource;

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	
	void use();

	void setBool(const std::string& name, const bool value) const;
	void setInt(const std::string& name, const int value) const;
	void setFloat(const  std::string& name, const float value) const;
	void setMat4(const  std::string& name, const float* value) const;
	void setVec3(const  std::string& name, const float* value) const;
	void setLight(const LightSource* light) const;
	void setLights(const std::vector<LightSource*>& lights) const;
private:
	void checkCompileErrors(unsigned int shader, std::string type);
};

