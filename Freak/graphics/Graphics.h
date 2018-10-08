#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<unordered_map>
#include"../Shader.h"
#include"../GameObject.h"

class Sprite{
public:
	Sprite(std::string path);
	void Draw(const GameObject& obj);
private:
	unsigned int TexID;
	static std::unordered_map<std::string, unsigned int> Path2TexID;
	static unsigned int get_id_or_load(std::string path);
	static Shader& get_shader();
};