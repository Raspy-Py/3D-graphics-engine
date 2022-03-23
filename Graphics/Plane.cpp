#include "Plane.h"
/* Plane coords
(x0,z1) ---- (x1,z1)
|  **   		   |
|      **   	   |
|		   **      |
|			   **  |
(x0,z0) ---- (x1,z0)

	# CCW order
*/

#define VERTEX_SIZE  (3 + 3 + 2) // coords, normals, texture
#define VERTEX(index, X,Y,Z, TX, TY) buffer[index] = (X); \
									 buffer[index+1] = (Y); \
									 buffer[index+2] = (Z); \
									 buffer[index+3] = (0); \
									 buffer[index+4] = (1); \
									 buffer[index+5] = (0); \
									 buffer[index+6] = (TX); \
									 buffer[index+7] = (TY); \
									 index += VERTEX_SIZE


Plane::Plane(float x0, float z0, float x1, float z1, float y)
{
	if (x0 >= x1 || z0 >= z1)
	{
		std::cout << "ERROR::PLANE::RENDER: wrong coordinates." << std::endl;
		exit(-1);
	}

	int index = 0;
	float xT =  x1 - x0;
	float zT = z1 - z0;

	attributes = new int[4];
	buffer = new float[VERTEX_SIZE * 6/* plane is rectangular*/];
	vertices = 6;
	attributes[0] = 3;
	attributes[1] = 3;
	attributes[2] = 2;
	attributes[3] = 0;
	
	VERTEX(index, x0, y, z0, 0, 0);
	VERTEX(index, x0, y, z1, 0, zT);
	VERTEX(index, x1, y, z0, xT, 0);

	VERTEX(index, x1, y, z0, xT, 0);
	VERTEX(index, x0, y, z1, 0, zT);
	VERTEX(index, x1, y, z1, xT, zT);
}