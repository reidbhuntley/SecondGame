#pragma once
#include <map>
#include "GLobject.h"
class ShaderProgram : public GLobject {
public:
	ShaderProgram(std::string vertexShaderPath, std::string fragmentShaderPath);
	~ShaderProgram();
	void use();
	GLuint getUniformLocation(std::string name);
private:
	std::map<std::string, GLuint> uniformLocations;
};