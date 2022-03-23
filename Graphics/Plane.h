#pragma once
#include <iostream>
#include "Drawable.h"

class Plane : public Drawable
{
public:
	Plane(float x0, float z0, float x1, float z1, float y);
};

