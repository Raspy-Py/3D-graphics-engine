#pragma once
#include <glad/glad.h>
#include "Drawable.h"

class Mesh
{
public:
	Mesh(const float* buffer, size_t vertices, const int* attrs);
	Mesh(Drawable* object);
	~Mesh();

	void draw(unsigned int primitive);
private:
	unsigned int VAO;
	unsigned int VBO; 
	size_t vertices;

	void loadObject(const float* buffer, size_t vertices, const int* attrs);
};

