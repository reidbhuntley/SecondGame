#pragma once
#include "GLobject.h"
#include "VBOattribData.h"

class VBO : public GLobject {
public:
	VBO();
	~VBO();
	void loadVBOattribData(VBOattribData* data);
};