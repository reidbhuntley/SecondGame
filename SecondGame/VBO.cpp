#include "VBO.h"
#include <iostream>

VBO::VBO(float vertices[], int size) {
	GLuint id;
	glGenBuffers(1, &id);
	this->initID(id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VBO::~VBO() {
	GLuint id = this->getID();
	GLuint* id_ptr = &id;
	glDeleteBuffers(1, id_ptr);
}
