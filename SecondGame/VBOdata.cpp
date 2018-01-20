#include "VBOdata.h"

VBOdata::VBOdata(
	void* vecs, GLuint attribID, GLint elementsPerVec, GLenum elementType, int length):
	vecs(vecs), attribID(attribID), elementsPerVec(elementsPerVec), elementType(elementType),
	length(length)
{}