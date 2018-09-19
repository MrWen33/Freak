#pragma once

#include<vector>
#include<string>
#include"Shader.h"
class GameObject {
public:
	static std::vector<GameObject> objects;
	std::string name;
	float xpos, ypos;

	GameObject(std::string name) {
		this->name = name;
		objects.push_back(*this);
		xpos = 0;
		ypos = 0;
	}
	virtual void Draw() {}
	virtual void Update(float deltaTime) {}
	virtual ~GameObject() {};
};
