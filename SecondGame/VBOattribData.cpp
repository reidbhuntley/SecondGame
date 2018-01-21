#include "VBOattribData.h"

VBOattribData::VBOattribData(
	GLuint attribID, void* vecs, GLint elementsPerVec, GLenum elementType, unsigned int length):
	vecs(vecs), attribID(attribID), elementsPerVec(elementsPerVec), elementType(elementType),
	length(length), elementSize(sizeof(elementType)), vectorSize(elementsPerVec*elementSize),
	totalSize(length*elementSize)
{}