#pragma once
#include <glad\glad.h>
#include <cstddef>
struct VBOattribData {
	const void* vecs;
	const GLuint attribID;
	const GLint elementsPerVec;
	const GLenum elementType;
	const unsigned int length;
	const std::size_t elementSize;
	const std::size_t vectorSize;
	const std::size_t totalSize;
public:
	VBOattribData(GLuint attribID, void* data, GLint elementsPerVec, GLenum elementType, unsigned int length);
};

