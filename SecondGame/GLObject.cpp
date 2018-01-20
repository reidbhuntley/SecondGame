#include "GLobject.h"

void GLobject::initID(GLuint id) {
	if (id_ == 0) {
		id_ = id;
	}
}

GLuint GLobject::getID() {
	return id_;
}

GLobject::GLobject(){}
GLobject::~GLobject() {}