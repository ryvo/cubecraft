#include "texture.hpp"

#include <SFML/Graphics/Image.hpp>

namespace cw
{
	bool Texture::loadFromFile(const std::string& filename) 
	{
		clear();

		sf::Image image;
		if (!image.loadFromFile(filename)) {
			return false;
		}

		// Generate texture name
		glGenTextures(1, &textureID);
		// Bind a named texture to a texturing target
		glBindTexture(GL_TEXTURE_2D, textureID);
		// Specify a two-dimensional texture image
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
		// Set texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		return true;
	}

	Texture::~Texture()
	{
		clear();
	}

	void Texture::clear() {
		glDeleteTextures(1, &textureID);
	}
}