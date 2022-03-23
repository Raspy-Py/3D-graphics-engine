#include "Texture.h"

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, this->texture);
}

void Texture::getTextureInfo(int& width, int& height, int& nrChannels)
{
	width = this->width;
	height = this->height;
	nrChannels = this->nrChannels;
}

Texture::Texture(const char* sourceFile, bool alpha)
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// load and generate the texture
	int width, height, nrChannels;
	unsigned char* data = stbi_load(sourceFile, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, (alpha ? GL_RGBA : GL_RGB), width, height, 0, (alpha ? GL_RGBA : GL_RGB), GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture: "  << sourceFile << std::endl;
	}
	//glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}

unsigned int Texture::getTexture()
{
	return texture;
}
