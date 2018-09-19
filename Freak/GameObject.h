#pragma once

#include<vector>
#include<string>
#include"Shader.h"
class GameObject {
public:
	static std::vector<GameObject*> objects;
	static void fresh_obj_sheet() {
		if (!should_fresh) return;
		for (int i = objects.size()-1; i >= 0; --i) {
			if (objects[i] == NULL) {
				objects.erase(objects.begin() + i);
			}
		}
		should_fresh = false;
	}
	std::string name;
	float xpos, ypos;

	GameObject(std::string name) {
		this->name = name;
		objects.push_back(this);
		xpos = 0;
		ypos = 0;
	}
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual ~GameObject() {
		auto this_iter = std::find(objects.begin(), objects.end(), this);
		*this_iter = NULL;
		should_fresh = true;
	};
private:
	static bool should_fresh;
};
