#pragma once
#include <glad\glad.h>
#include <algorithm>

struct GLObject {
protected:
	void initID(int id);
private:
	GLuint id_ = 0; //Cannot leave this uninitialized.
	
public:
	GLObject();
	virtual ~GLObject() = 0;
	int getID();
};

