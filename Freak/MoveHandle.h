#pragma once

#include"GameObject.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"WindowFunc.h"
class GameObject;

class MoveHandle {
public:
	virtual void update(GameObject* obj) = 0;
	virtual ~MoveHandle() {}
};

class InputMovement: public MoveHandle {
public:
	void update(GameObject* obj) override;
};