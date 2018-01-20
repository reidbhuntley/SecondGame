#pragma once
#include "GLobject.h"
#include "VBO.h"
#include "VBOattribData.h"
#include <vector>
#include <memory>

class VAO : public GLobject {
public:
	VAO();
	~VAO();
	void prepareVBOattribData(VBOattribData* data);
	void addVBO();
private:
	std::vector<std::unique_ptr<VBO>> vbos;
	std::vector<VBOattribData*> attribDataQueue;
};

