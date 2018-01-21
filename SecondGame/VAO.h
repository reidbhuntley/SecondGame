#pragma once
#include "GLobject.h"
#include "VBO.h"
#include "VBOattribData.h"
#include "EAO.h"
#include <vector>
#include <memory>

class VAO : public GLobject {
public:
	VAO();
	~VAO();
	void prepareVBOattribData(void* data, GLuint attribID, GLint elementsPerVec, GLenum elementType, unsigned int length);
	void loadVBO();
	void loadElements(unsigned int* data, unsigned int length);
	void bind();
	void drawElements();
private:
	std::vector<std::unique_ptr<VBO>> vbos;
	std::vector<VBOattribData*> attribDataQueue;
	std::unique_ptr<EAO> elements;
	unsigned int elementCount = 0;
	unsigned int totalBytes = 0;
};

