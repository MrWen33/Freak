#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<iostream>

unsigned int loadMaterial(std::string path);

template <class T>
inline void clamp(T& n, T max, T min) {
	if (n > max)n = max;
	else if (n < min)n = min;
}

void display_FPS(float deltaTime);