#include "WindowFunc.h"
#include<iostream>
using std::cout;
using std::endl;
using std::string;

GLFWwindow* openglInit(string name, int wid, int height, GLFWframebuffersizefun kbd_callback, GLFWcursorposfun mouse_callback) {
	/*
	Init opengl Window.
	*/
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(wid, height, name.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return NULL;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return NULL;
	}

	glfwSetFramebufferSizeCallback(window, kbd_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	//���õ㾫��
	glEnable(GL_PROGRAM_POINT_SIZE);
	//����alpha���
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return window;
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void process_input(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
