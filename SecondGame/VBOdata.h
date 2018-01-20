#pragma once
#include <glad\glad.h>
struct VBOdata {
	void* vecs;
	GLuint attribID;
	GLint elementsPerVec;
	GLenum elementType;
	int length;
public:
	VBOdata(void* data, GLuint attribID, GLint elementsPerVec, GLenum elementType, int length);
};

