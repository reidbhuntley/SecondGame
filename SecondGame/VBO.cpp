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
void VBO::loadVBOattribData(VBOattribData** data, unsigned int length, unsigned int verticesCount) {
	bind();

	std::size_t totalSize = 0;
	std::size_t totalStride = 0;
	for (unsigned int i = 0; i < length; i++) {
		VBOattribData* dataElement = data[i];
		std::size_t stride = dataElement->vectorSize;
		std::size_t size = verticesCount * stride;
		totalStride += stride;
		totalSize += size;
		data[i]->totalSize = size;
	}
	
	if (bufferIsAllocated) {
		free(buffer);
	}
	buffer = malloc(totalSize);
	bufferIsAllocated = true;

	std::size_t offset = 0;
	for (unsigned int i = 0; i < length; i++) {
		VBOattribData* dataElement = data[i];
		void* ptr = static_cast<bool*>(buffer) + offset;
		for (unsigned int j = 0; j < dataElement->totalSize; j += dataElement->vectorSize) {
			std::memcpy(ptr, (bool*)(dataElement->vecs) + j, dataElement->vectorSize);
			ptr = static_cast<bool*>(ptr) + totalStride;
		}
		glVertexAttribPointer(dataElement->attribID, dataElement->elementsPerVec, dataElement->elementType,
			GL_FALSE, totalStride, (void*)(offset));
		glEnableVertexAttribArray(dataElement->attribID);
		offset += dataElement->vectorSize;
	}
	glBufferData(GL_ARRAY_BUFFER, totalSize, buffer, GL_STATIC_DRAW);
}

void VBO::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, getID());
}