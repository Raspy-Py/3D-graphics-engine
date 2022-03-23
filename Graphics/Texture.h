#pragma once
#include <glad/glad.h>
#include <iostream>
#include "../Deps/std_image.h"


class Texture
{
	unsigned int texture;
	int width;
	int height;
	int nrChannels;

public:
	Texture(const char* sourceFile, bool alpha = false);

	void bind();
	void getTextureInfo(int& width, int& height, int& nrChannels);
	unsigned int getTexture();
};

