#pragma once
#include "GLobject.h"
#include "VBOattribData.h"
#include <memory>

class VBO : public GLobject {
public:
	VBO();
	~VBO();
	void bind();
	void loadVBOattribData(VBOattribData** data, unsigned int length, std::size_t totalBytes, std::size_t totalStride);
private:
	void* buffer;
	bool bufferIsAllocated = false;
};