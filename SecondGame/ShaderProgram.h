#pragma once
#include <iostream>
#include "GLObject.h"
class ShaderProgram : public GLObject {
public:
	ShaderProgram(std::string vertexShaderPath, std::string fragmentShaderPath);
};