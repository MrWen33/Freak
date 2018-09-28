#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game {
public:
	GLFWwindow* window;
	GameState State;
	int height;
	int width;
	void Init();
	void Update(float deltaTime);
	void Render();
};