#pragma once
#include "GLobject.h"
#include <memory>

class GLobjectHandler {
private:
	std::unique_ptr<GLobject> obj_;
public:
	GLobjectHandler(GLobject* obj);

	//Delete the copy constructor/assignment.
	GLobjectHandler(const GLobjectHandler &) = delete;
	GLobjectHandler &operator=(const GLobjectHandler &) = delete;

	GLobjectHandler(GLobjectHandler &&other);
	GLobjectHandler& operator=(GLobjectHandler &&other);

	GLobject* obj();
	int getID();
};

