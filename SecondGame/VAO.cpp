#include "VAO.h"
#include <vector>

VAO::VAO() {
	GLuint id;
	glGenVertexArrays(1, &id);
	this->initID(id);
}

VAO::~VAO() {
	GLuint id = this->getID();
	GLuint* id_ptr = &id;
	glDeleteVertexArrays(1, id_ptr);
}

void VAO::prepareVBOattribData(GLuint attribID, void* data, GLint elementsPerVec, GLenum elementType, unsigned int length) {
	attribDataQueue.push_back(new VBOattribData(attribID,data,elementsPerVec,elementType,length));
	totalBytes += attribDataQueue.back()->totalSize;
}

void VAO::loadVBO() {
	bind();

	vbos.push_back(std::unique_ptr<VBO>(new VBO()));
	VBO* vbo = vbos.back().get();
	vbo->loadVBOattribData(&attribDataQueue[0], attribDataQueue.size(), totalBytes);
	for (int i = 0; i < attribDataQueue.size(); i++) {
		delete attribDataQueue[i];
	}
	attribDataQueue.clear();
	totalBytes = 0;
}

void VAO::loadElements(unsigned int* data, unsigned int length) {
	bind();

	elements = std::unique_ptr<EAO>(new EAO());
	elements.get()->load(data, length);
	elementCount = length;
}

void VAO::bind() {
	glBindVertexArray(getID());
}

void VAO::drawElements() {
	bind();

	glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, 0);
}