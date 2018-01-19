#include "ShaderProgram.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <glad\glad.h>

ShaderProgram::ShaderProgram(std::string vertexShaderFilename, std::string fragmentShaderFilename) {
	char c;
	std::vector<char> chars;
	std::ifstream inFile;

	inFile.open("../res/shaders/" + vertexShaderFilename);
	if (!inFile) {
		std::cerr << "Unable to open vertex shader file " << vertexShaderFilename;
		exit(1);   // call system to stop
	}
	while ((c = inFile.get()) != EOF) {
		chars.push_back(c);
	}
	inFile.close();
	const char* vertexShaderSource = &chars[0];
	chars.clear();

	inFile.open("../res/shaders/" + fragmentShaderFilename);
	if (!inFile) {
		std::cerr << "Unable to open vertex shader file " << fragmentShaderFilename;
		exit(1);   // call system to stop
	}
	while ((c = inFile.get()) != EOF) {
		chars.push_back(c);
	}
	inFile.close();
	const char* fragmentShaderSource = &chars[0];

	// build and compile our shader program
	// ------------------------------------
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
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	this->initID(shaderProgram);
}

GLObject::~GLObject() {
	glUseProgram(0);
	glDeleteProgram(this->getID());
}