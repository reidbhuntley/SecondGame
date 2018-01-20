#include "GLobjectHandler.h"
#include <memory>

GLobjectHandler::GLobjectHandler(GLobject* obj) : obj_(obj) {}

GLobjectHandler::GLobjectHandler(GLobjectHandler &&other) : obj_(other.obj_.release()) {}

GLobjectHandler& GLobjectHandler::operator=(GLobjectHandler &&other) {
	//ALWAYS check for self-assignment.
	if (this != &other) {
		obj_.reset(other.obj_.release());
	}
	return *this;
}

GLobject* GLobjectHandler::obj() {
	if (obj_) {
		return obj_.get();
	}
	return NULL;
}

int GLobjectHandler::getID() {
	if (obj_) {
		return obj_.get()->getID();
	}
	return 0;
}