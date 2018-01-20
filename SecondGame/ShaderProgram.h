#pragma once
#include <iostream>
#include "GLobject.h"
class ShaderProgram : public GLobject {
public:
	ShaderProgram(std::string vertexShaderPath, std::string fragmentShaderPath);
	~ShaderProgram();
	void use();
};