#pragma once
#include "GLObject.h"
#include <memory>

class GLObjectHandler
{
private:
	std::unique_ptr<GLObject> obj_;
public:
	GLObjectHandler(GLObject* obj);

	//Delete the copy constructor/assignment.
	GLObjectHandler(const GLObjectHandler &) = delete;
	GLObjectHandler &operator=(const GLObjectHandler &) = delete;

	GLObjectHandler(GLObjectHandler &&other);
	GLObjectHandler& operator=(GLObjectHandler &&other);

	int id();
};

