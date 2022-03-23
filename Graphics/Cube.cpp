#include "Cube.h"

#define VERTEX_SIZE (3 + 3 + 3)
#define VERTEX(f,X,Y,Z, R,G,B, NX,NY,NZ) buffer[f] = (X); \
								buffer[f + 1] = (Y); \
								buffer[f + 2] = (Z); \
								buffer[f + 3] = (R); \
								buffer[f + 4] = (G); \
								buffer[f + 5] = (B); \
								buffer[f + 6] = (NX); \
								buffer[f + 7] = (NY); \
								buffer[f + 8] = (NZ); \
								f += VERTEX_SIZE;
#include <iostream>
Cube::Cube(float size, glm::vec3 origin, glm::vec3 color)
{
	render(size, origin, color, false);
}

Cube::Cube(bool textured)
{
	render(1.0f, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), true);
}

Cube::~Cube()
{
	delete [] attributes;
	delete[] buffer;
}

void Cube::render(float size, glm::vec3 origin, glm::vec3 color, bool textured)
{
	attributes = new int[4];
	attributes[0] = 3;
	attributes[1] = 3;
	attributes[2] = 3;
	attributes[3] = 0;

	vertices = 36;

	buffer = new float[vertices * VERTEX_SIZE];

	float hSize = size / 2;
	size_t index = 0;
	float x = origin.x;
	float y = origin.y;
	float z = origin.z;

	glm::vec3 tex(0, 0, 0);
	
	glm::vec3& coord = (textured ? tex : color);

	VERTEX(index, x - hSize, y + hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, 1.0f, 0.0f); 
	VERTEX(index, x - hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, 1.0f, 0.0f);
	VERTEX(index, x + hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, 1.0f, 0.0f);

	VERTEX(index, x - hSize, y + hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, 1.0f, 0.0f);
	VERTEX(index, x + hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, 1.0f, 0.0f);
	VERTEX(index, x + hSize, y + hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, 1.0f, 0.0f);


	VERTEX(index, x - hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, -1.0f, 0.0f);
	VERTEX(index, x + hSize, y - hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, -1.0f, 0.0f);
	VERTEX(index, x - hSize, y - hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, -1.0f, 0.0f);

	VERTEX(index, x - hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, -1.0f, 0.0f);
	VERTEX(index, x + hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, -1.0f, 0.0f);
	VERTEX(index, x + hSize, y - hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, -1.0f, 0.0f);


	VERTEX(index, x + hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, 1.0f, 0.0f, 0.0f);
	VERTEX(index, x + hSize, y + hSize, z - hSize, coord.x, coord.y, coord.z, 1.0f, 0.0f, 0.0f);
	VERTEX(index, x + hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, 1.0f, 0.0f, 0.0f);

	VERTEX(index, x + hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, 1.0f, 0.0f, 0.0f);
	VERTEX(index, x + hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, 1.0f, 0.0f, 0.0f);
	VERTEX(index, x + hSize, y - hSize, z + hSize, coord.x, coord.y, coord.z, 1.0f, 0.0f, 0.0f);


	VERTEX(index, x - hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, -1.0f, 0.0f, 0.0f);
	VERTEX(index, x - hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, -1.0f, 0.0f, 0.0f);
	VERTEX(index, x - hSize, y + hSize, z - hSize, coord.x, coord.y, coord.z, -1.0f, 0.0f, 0.0f);

	VERTEX(index, x - hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, -1.0f, 0.0f, 0.0f);
	VERTEX(index, x - hSize, y - hSize, z + hSize, coord.x, coord.y, coord.z, -1.0f, 0.0f, 0.0f);
	VERTEX(index, x - hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, -1.0f, 0.0f, 0.0f);


	VERTEX(index, x - hSize, y - hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, 1.0f);
	VERTEX(index, x + hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, 1.0f);
	VERTEX(index, x - hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, 1.0f);

	VERTEX(index, x - hSize, y - hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, 1.0f);
	VERTEX(index, x + hSize, y - hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, 1.0f);
	VERTEX(index, x + hSize, y + hSize, z + hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, 1.0f);


	VERTEX(index, x - hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, -1.0f);
	VERTEX(index, x - hSize, y + hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, -1.0f);
	VERTEX(index, x + hSize, y + hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, -1.0f);

	VERTEX(index, x - hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, -1.0f);
	VERTEX(index, x + hSize, y + hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, -1.0f);
	VERTEX(index, x + hSize, y - hSize, z - hSize, coord.x, coord.y, coord.z, 0.0f, 0.0f, -1.0f);
}
