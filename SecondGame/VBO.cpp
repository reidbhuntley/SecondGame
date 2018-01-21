#include <cstring>
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
	if (bufferIsAllocated) {
		free(buffer);
	}
}
void VBO::loadVBOattribData(VBOattribData** data, unsigned int length, std::size_t totalBytes) {
	bind();
	
	if (bufferIsAllocated) {
		free(buffer);
	}
	buffer = malloc(totalBytes);
	bufferIsAllocated = true;

	void* ptr = buffer;
	std::size_t offset = 0;
	for (unsigned int i = 0; i < length; i++) {
		VBOattribData* dataElement = data[i];
		std::memcpy(ptr, dataElement->vecs, dataElement->totalSize);
		glVertexAttribPointer(dataElement->attribID, dataElement->elementsPerVec, dataElement->elementType,
			GL_FALSE, 0, (void*)(offset));
		glEnableVertexAttribArray(dataElement->attribID);
		ptr = static_cast<bool*>(ptr) + dataElement->totalSize;
		offset += dataElement->totalSize;
	}
	glBufferData(GL_ARRAY_BUFFER, totalBytes, buffer, GL_STATIC_DRAW);

}

void VBO::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, getID());
}