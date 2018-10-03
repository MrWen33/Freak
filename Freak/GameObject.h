#pragma once
#include<vector>
#include<memory>
#include<string>
#include"Shader.h"
#include"MoveHandle.h"
#include"Physics.h"
#include"graphics\Graphics.h"
class Sprite;
class MoveHandle;
class VelocitySetter;
class BoxCollider;

enum MoveState {
	NONE, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT
};

class GameObject {
	friend class GameObjectPool;
public:
	void Draw();
	bool Update(float deltaTime);//在释放瞬间帧返回true
	void Init(std::string name, float xpos = 0, float ypos = 0, 
		std::shared_ptr<MoveHandle> moveHandle = NULL, 
		std::shared_ptr<VelocitySetter> velocitySetter = NULL, 
		std::shared_ptr<Sprite> sprite = NULL, BoxCollider* collider=NULL);
	virtual void OnCollisionWith(GameObject& other);
	virtual bool IsCollisionWith(GameObject& other);
	virtual ~GameObject() {};
	bool IsInUse();
	GameObject* GetNext() { return next; };
	BoxCollider* GetWorldCollider();
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
			std::unique_ptr<BoxCollider> collider;
			std::shared_ptr<MoveHandle> moveHandle;
			std::shared_ptr<VelocitySetter> velocitySetter;
			std::shared_ptr<Sprite> sprite;
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
	void create(std::string name, float xpos, float ypos, std::shared_ptr<MoveHandle> moveHandle = NULL,
		std::shared_ptr<VelocitySetter> velocitySetter = NULL,
		std::shared_ptr<Sprite> sprite = NULL, BoxCollider* collider = NULL);
	void create(std::string name, std::shared_ptr<MoveHandle> moveHandle = NULL,
		std::shared_ptr<VelocitySetter> velocitySetter = NULL,
		std::shared_ptr<Sprite> sprite = NULL, BoxCollider* collider = NULL);
	void update(float deltaTime);
	void Draw();
	void DoCollisionTest();
	void FreshObjMesh();
private:
	static const int MESH_HEIGHT = 10;
	static const int MESH_WIDTH = 10;
	std::vector<GameObject*> obj_mesh[MESH_HEIGHT][MESH_WIDTH];
	static const int POOL_SIZE = 10000;
	GameObject * first_avaliable;
	GameObject objs[POOL_SIZE];
};
