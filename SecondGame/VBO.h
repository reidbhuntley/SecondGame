#pragma once
#include "GLobject.h"
#include "VBOattribData.h"
#include <memory>

class VBO : public GLobject {
public:
	VBO();
	~VBO();
	void bind();
	void loadVBOattribData(VBOattribData** data, unsigned int length, unsigned int verticesCount);
private:
	void* buffer;
	bool bufferIsAllocated = false;
};