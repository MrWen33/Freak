#pragma once
#include<vector>
#include<memory>
#include<string>
#include"Shader.h"
#include"graphics\Graphics.h"

//GameObject����ӿ�
class GameObject {
public:
	GameObject() {};
	virtual void Draw()=0;
	virtual void Update(double deltaTime)=0;
};
