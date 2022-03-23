#include "Mesh.h"

Mesh::Mesh(const float* buffer, size_t vertices, const int* attrs)
{
	loadObject(buffer, vertices, attrs);
}

Mesh::Mesh(Drawable* object)
{
	loadObject(object->buffer, object->vertices, object->attributes);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Mesh::draw(unsigned int primitive)
{
	glBindVertexArray(VAO);
	glDrawArrays(primitive, 0, vertices);
	glBindVertexArray(0);
}
#include <iostream>
void Mesh::loadObject(const float* buffer, size_t vertices, const int* attrs)
{
	this->vertices = vertices;
	int vertexSize = 0;

	for (int i = 0; attrs[i]; i++)
		vertexSize += attrs[i];

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexSize * vertices, buffer, GL_STATIC_DRAW);

	//attributes
	int offset = 0;
	for (int i = 0; attrs[i]; i++)
	{
		int size = attrs[i];
		glVertexAttribPointer(i, size, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)(offset * sizeof(float)));
		glEnableVertexAttribArray(i);
		offset += size;
	}

	glBindVertexArray(0);
}
