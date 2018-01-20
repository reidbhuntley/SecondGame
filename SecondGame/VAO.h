#pragma once
#include "GLobject.h"
#include "VBO.h"
#include <vector>
#include <memory>

class VAO : public GLobject {
public:
	VAO();
	~VAO();
	void addVBO(float vertices[], int length);
private:
	std::vector<std::unique_ptr<VBO>> vbos;
};

