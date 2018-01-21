#pragma once
#include <map>
#include "GLobject.h"
class ShaderProgram : public GLobject {
public:
	ShaderProgram(std::string vertexShaderPath, std::string fragmentShaderPath);
	~ShaderProgram();
	void use();
	GLuint getUniformLocation(std::string name);
	void setBool(std::string name, bool value);
	void setInt(std::string name, int value);
	void setFloat(std::string name, float value);
};