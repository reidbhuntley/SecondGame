#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <fstream>
#include "GLobjectHandler.h"
#include "ShaderProgram.h"
#include "VAO.h"

GLFWwindow* createContext();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
	GLFWwindow* window = createContext();
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	ShaderProgram program("vertexShader.txt", "fragmentShader.txt");

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		0.5f, -0.5f, 0.0f, // right 
		0.0f,  0.5f, 0.0f  // top   
	};
	VAO vao;
	vao.prepareVBOattribData(new VBOattribData(vertices, 0, 3, GL_FLOAT, 9));
	vao.addVBO();

	// render loop
	while (!glfwWindowShouldClose(window)) {
		// input
		processInput(window);

		// rendering commands
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(program.getID());
		glBindVertexArray(vao.getID());
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// check and call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

GLFWwindow* createContext() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(-1);
	}
	return window;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}