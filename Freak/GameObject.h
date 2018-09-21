#pragma once

#include<vector>
#include<string>
#include"Shader.h"
#include"MoveHandle.h"
#include"Physics.h"
#include"graphics\Graphics.h"
class Sprite;
class MoveHandle;
class VelocitySetter;

enum MoveState {
	NONE, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT
};

class GameObject {
public:
	static std::vector<GameObject*> objects;
	static void fresh_obj_sheet();
	std::string name;
	float xpos, ypos;
	MoveState dir;

	MoveHandle* moveHandle;
	VelocitySetter* velocitySetter;
	Sprite* sprite;

	GameObject(std::string name, MoveHandle* moveHandle=NULL, VelocitySetter* velocitySetter=NULL, Sprite* sprite=NULL);
	virtual void Draw();;
	virtual void Update(float deltaTime);;
	virtual ~GameObject();;
private:
	static bool should_fresh;
};
