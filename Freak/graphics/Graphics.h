#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<unordered_map>
#include"../Shader.h"

class Sprite {
public:
	Sprite(std::string path);
	void SetPos(float x, float y);
	void Draw();
private:
	unsigned int TexID;
	float xpos, ypos;
	static std::unordered_map<std::string, unsigned int> Path2TexID;
	static unsigned int get_id_or_load(std::string path);
	static Shader& get_shader();
};