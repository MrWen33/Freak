#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include"GameObject.h"
#include"utils.h"
using std::string;

class Player :public GameObject {
public:
	unsigned int imgID;
	unsigned int VAO;
	float pos[9] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.0f,  0.5f
	};

	Player(string name, string imgPath, float xpos=0, float ypos = 0): GameObject(name) {
		imgID = loadMaterial(imgPath);
		this->pos[0] = xpos;
		this->pos[1] = ypos;
		unsigned int VBO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), pos, GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);
	}
	void Update(float deltaTime) override {
		
	}
	void Draw(Shader& shader) override {
		shader.use();
		shader.setFloat("sprite_tex", 0);
		glBindVertexArray(VAO);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, imgID);
		glDrawArrays(GL_POINTS, 0, 1);
		glBindVertexArray(0);
	}
};