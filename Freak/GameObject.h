#pragma once
#include<vector>
#include<memory>
#include<string>
#include"Shader.h"
#include"graphics\Graphics.h"

//GameObject³éÏó½Ó¿Ú
class GameObject {
public:
	GameObject() {};
	virtual void Draw()=0;
	virtual void Update(double deltaTime)=0;
};
