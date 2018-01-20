#pragma once
#include "GLobject.h"

class EAO : public GLobject {
public:
	EAO();
	~EAO();
	void load(unsigned int* data, unsigned int length);
};

