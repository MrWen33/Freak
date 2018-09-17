#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>

class WindowInfo{
public:
	static GLFWwindow* window;
	static int height;
	static int width;
};

GLFWwindow* openglInit(std::string name, int wid, int height, GLFWframebuffersizefun kbd_callback=NULL, GLFWcursorposfun mouse_callback=NULL);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);