#include "GLObjectHandler.h"
#include <memory>

GLObjectHandler::GLObjectHandler(GLObject* obj) : obj_(obj) {}

GLObjectHandler::GLObjectHandler(GLObjectHandler &&other) : obj_(other.obj_.release()) {}

GLObjectHandler& GLObjectHandler::operator=(GLObjectHandler &&other) {
	//ALWAYS check for self-assignment.
	if (this != &other) {
		obj_.reset(other.obj_.release());
	}
	return *this;
}

int GLObjectHandler::id() {
	if (obj_) {
		return obj_.get()->getID();
	}
	return 0;
}