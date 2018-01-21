#include "VBOattribData.h"

VBOattribData::VBOattribData(
	GLuint attribID, void* vecs, GLint elementsPerVec, GLenum elementType):
	vecs(vecs), attribID(attribID), elementsPerVec(elementsPerVec), elementType(elementType),
	elementSize(sizeof(elementType)), vectorSize(elementsPerVec * elementSize)
{}