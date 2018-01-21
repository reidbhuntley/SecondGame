#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Texture.h"
#include <iostream>

Texture::Texture(std::string textureFilename, GLenum wrap, GLenum minFilter, GLenum magFilter) {
	GLuint id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	// load and generate the texture
	std::string texturePath = "../res/textures/" + textureFilename;
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(&texturePath[0], &width, &height, &nrChannels, 0);
	if (data) {
		GLenum channels = nrChannels == 4 ? GL_RGBA : GL_RGB;
		glTexImage2D(GL_TEXTURE_2D, 0, channels, width, height, 0, channels, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
	} else {
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	this->initID(id);
}

Texture::~Texture() {
	GLuint id = this->getID();
	GLuint* id_ptr = &id;
	glDeleteTextures(1, id_ptr);
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, getID());
}

void Texture::bind(GLenum textureUnit) {
	glActiveTexture(textureUnit);
	bind();
}