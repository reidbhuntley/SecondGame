#include "GLObject.h"

void GLObject::initID(int id) {
	if (id_ == 0) {
		id_ = id;
	}
}

int GLObject::getID() {
	return id_;
}

GLObject::GLObject(){}