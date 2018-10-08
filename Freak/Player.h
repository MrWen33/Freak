#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include"GameObject.h"
#include"utils.h"
#include"graphics\Graphics.h"
using std::string;

class Player : public GameObject {
public:
	Player(float xpos, float ypos, std::shared_ptr<Sprite> sprite, float speed=0.02) {
		this->Init("Player", 0, 0, InputMovement::getInstance(), std::shared_ptr<VelocitySetter>(new ConstVelocitySetter(speed)), sprite, std::move(std::unique_ptr<BoxCollider>(new BoxCollider(Bound2f(0, 0, 0.2, 0.2)))));
	}
};