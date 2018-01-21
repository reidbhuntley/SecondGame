#pragma once
#include <iostream>
#include "GLobject.h"

class Texture : public GLobject {
public:
	Texture(std::string textureFilename, GLenum wrap, GLenum minFilter, GLenum magFilter);
	~Texture();
	void bind();
};