#pragma once
#include <glad\glad.h>
#include <algorithm>

struct GLobject {
protected:
	void initID(GLuint id);
private:
	GLuint id_ = 0; //Cannot leave this uninitialized.
public:
	GLobject();
	virtual ~GLobject();
	GLobject(const GLobject &) = delete;
	GLobject &operator=(const GLobject &) = delete;
	GLuint getID();
};