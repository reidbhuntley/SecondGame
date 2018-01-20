#pragma once
#include <glad\glad.h>
struct VBOattribData {
	void* vecs;
	GLuint attribID;
	GLint elementsPerVec;
	GLenum elementType;
	unsigned int length;
public:
	VBOattribData(void* data, GLuint attribID, GLint elementsPerVec, GLenum elementType, unsigned int length);
};

