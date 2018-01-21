#pragma once
#include <glad\glad.h>
struct VBOattribData {
	const void* vecs;
	const GLuint attribID;
	const GLint elementsPerVec;
	const GLenum elementType;
	const unsigned int length;
	const unsigned int elementSize;
	const unsigned int totalSize;
public:
	VBOattribData(void* data, GLuint attribID, GLint elementsPerVec, GLenum elementType, unsigned int length);
};

