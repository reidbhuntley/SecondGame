#include "ShaderProgram.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <glad\glad.h>

ShaderProgram::ShaderProgram(std::string vertexShaderFilename, std::string fragmentShaderFilename) {
	char c;
	std::vector<char> vertexChars;
	std::vector<char> fragmentChars;
	std::ifstream inFile;

	inFile.open("../res/shaders/" + vertexShaderFilename);
	if (!inFile) {
		std::cerr << "Unable to open vertex shader file " << vertexShaderFilename;
		exit(1);   // call system to stop
	}
	while ((c = inFile.get()) != EOF) {
		vertexChars.push_back(c);
	}
	inFile.close();
	vertexChars.push_back('\0');
	const char* vertexShaderSource = &vertexChars[0];

	inFile.open("../res/shaders/" + fragmentShaderFilename);
	if (!inFile) {
		std::cerr << "Unable to open fragment shader file " << fragmentShaderFilename;
		exit(1);   // call system to stop
	}
	while ((c = inFile.get()) != EOF) {
		fragmentChars.push_back(c);
	}
	inFile.close();
	fragmentChars.push_back('\0');
	const char* fragmentShaderSource = &fragmentChars[0];

	// vertex shader
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	this->initID(shaderProgram);
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(this->getID());
}

void ShaderProgram::use() {
	glUseProgram(getID());
}

GLuint ShaderProgram::getUniformLocation(std::string name) {
	std::map<std::string, GLuint>::iterator it = uniformLocations.find(name);
	if (it != uniformLocations.end()) {
		return it->second;
	} else {
		GLuint location = glGetUniformLocation(getID(), &name[0]);
		uniformLocations.insert(std::pair<std::string, GLuint>(name, location));
		return location;
	}
}