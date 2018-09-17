#pragma once

#include<vector>
#include<string>
#include"Shader.h"
class GameObject {
public:
	static std::vector<GameObject> objects;

	std::string name;

	GameObject(std::string name) {
		this->name = name;
		objects.push_back(*this);
	}
	virtual void Draw(Shader& shader) {}
	virtual void Update(float deltaTime) {}
};
