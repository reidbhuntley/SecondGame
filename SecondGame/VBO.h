#pragma once
#include "GLobject.h"

class VBO : public GLobject {
public:
	VBO(float vertices[], int length);
	~VBO();
};

