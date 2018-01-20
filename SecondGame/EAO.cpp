#include "EAO.h"

EAO::EAO() {
	GLuint id;
	glGenBuffers(1, &id);
	this->initID(id);
}

void EAO::load(unsigned int* data, unsigned int length) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, getID());
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

EAO::~EAO() {
	GLuint id = this->getID();
	GLuint* id_ptr = &id;
	glDeleteBuffers(1, id_ptr);
}