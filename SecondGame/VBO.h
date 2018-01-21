#pragma once
#include "GLobject.h"
#include "VBOattribData.h"

class VBO : public GLobject {
public:
	VBO();
	~VBO();
	void bind();
	void loadVBOattribData(VBOattribData* data, unsigned int previousBytes, unsigned int totalBytes);
};