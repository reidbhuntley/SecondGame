#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Texture.h"

Texture::Texture(std::string textureFilename, GLenum wrap, GLenum minFilter, GLenum magFilter) {
	GLuint id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
	// load and generate the texture
	std::string texturePath = "../res/textures/" + textureFilename;
	int width, height, nrChannels;
	unsigned char *data = stbi_load(&texturePath[0], &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
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