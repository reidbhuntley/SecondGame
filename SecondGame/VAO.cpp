#include "VAO.h"
#include <vector>
#include <iostream>

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

void VAO::addVBO(float vertices[], int size) {
	glBindVertexArray(getID());
	vbos.push_back(std::unique_ptr<VBO>(new VBO(vertices, size)));
	glBindVertexArray(0);
}
