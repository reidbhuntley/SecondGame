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

void VAO::prepareVBOattribData(VBOattribData* data) {
	attribDataQueue.push_back(data);
}

void VAO::addVBO() {
	vbos.push_back(std::unique_ptr<VBO>(new VBO()));
	VBO* vbo = vbos.back().get();
	glBindVertexArray(getID());
	for (int i = 0; i < attribDataQueue.size(); i++) {
		vbo->loadVBOattribData(attribDataQueue[i]);
		delete attribDataQueue[i];
	}
	attribDataQueue.clear();
}
