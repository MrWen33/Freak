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
	friend class GameObjectPool;
public:
	void Draw();
	bool Update(float deltaTime);//���ͷ�˲��֡����true
	void Init(std::string name, MoveHandle* moveHandle = NULL, VelocitySetter* velocitySetter = NULL, Sprite* sprite = NULL);
	virtual ~GameObject() {};
	bool IsInUse();
	GameObject* GetNext() { return next; };
	void SetNext(GameObject* _next) {
		next = _next;
	};
	union
	{
		struct
		{
			std::string name;
			float xpos, ypos;
			MoveState dir;
			MoveHandle* moveHandle;
			VelocitySetter* velocitySetter;
			Sprite* sprite;
		} live;
		GameObject* next;
	};

private:
	bool in_use;
	GameObject();
};

class GameObjectPool {
public:
	GameObjectPool();
	void create(std::string name, MoveHandle* moveHandle = NULL, VelocitySetter* velocitySetter = NULL, Sprite* sprite = NULL);
	void update(float deltaTime);
private:
	static const int POOL_SIZE = 10000;
	GameObject * first_avaliable;
	GameObject objs[POOL_SIZE];
};
