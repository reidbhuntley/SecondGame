#include "VBO.h"

VBO::VBO() {
	GLuint id;
	glGenBuffers(1, &id);
	this->initID(id);
}
VBO::~VBO() {
	GLuint id = this->getID();
	GLuint* id_ptr = &id;
	glDeleteBuffers(1, id_ptr);
}
void VBO::loadVBOattribData(VBOattribData* data) {
	bind();

	unsigned int typeSize = sizeof(data->elementType);
	glBufferData(GL_ARRAY_BUFFER, data->length * typeSize, data->vecs, GL_STATIC_DRAW);
	glVertexAttribPointer(data->attribID, data->elementsPerVec, data->elementType, GL_FALSE,
		data->elementsPerVec * typeSize, (void*)0);
	glEnableVertexAttribArray(data->attribID);
}

void VBO::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, getID());
}