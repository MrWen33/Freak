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
	Player(double x, double y, std::string path):m_x(x), m_y(y), m_sprite(path) {
	}
	void Draw() override;
	void Update(double deltaTime) override;
private:
	double m_x, m_y;
	Sprite m_sprite;
};