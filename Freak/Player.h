#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include"GameObject.h"
#include"utils.h"
#include"graphics\Graphics.h"
using std::string;

class Player :public GameObject {
public:
	Sprite sprite;

	Player(string name, string imgPath, float xpos=0, float ypos = 0): GameObject(name), sprite(imgPath) {
		
	}
	void Update(float deltaTime) override {
		
	}
	void Draw(Shader& shader) override {
		sprite.Draw();
	}
};