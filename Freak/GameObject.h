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

struct Coordinates {
	float x, y;
};

class GameObject {
	friend class GameObjectFactory;
public:
	virtual void Init(std::string name, float xpos = 0, float ypos = 0,
		std::shared_ptr<MoveHandle> moveHandle = NULL,
		std::shared_ptr<VelocitySetter> velocitySetter = NULL,
		std::shared_ptr<Sprite> sprite = NULL,
		std::unique_ptr<BoxCollider> collider = NULL);
	void Draw();
	bool isMove();
	MoveState getDir() { return dir; };
	void setDir(MoveState Dir) { dir = Dir; }
	Coordinates getPos() const { return pos; }
	void setPos(float x, float y) { pos.x = x, pos.y = y; }
	bool Update(float deltaTime);
	virtual void OnCollisionWith(GameObject& other);
	virtual bool IsCollisionWith(GameObject& other);
	virtual ~GameObject() {};

	BoxCollider* GetWorldCollider();
protected:
	GameObject();
private:
	std::string name;
	Coordinates pos;
	MoveState dir;
	std::unique_ptr<BoxCollider> collider;
	std::shared_ptr<MoveHandle> moveHandle;
	std::shared_ptr<VelocitySetter> velocitySetter;
	std::shared_ptr<Sprite> sprite;
};

class GameObjectFactory {
public:
	std::shared_ptr<GameObject> getGameObject(
		std::string name, float xpos = 0, float ypos = 0,
		std::shared_ptr<MoveHandle> moveHandle = NULL,
		std::shared_ptr<VelocitySetter> velocitySetter = NULL,
		std::shared_ptr<Sprite> sprite = NULL,
		std::unique_ptr<BoxCollider> collider = NULL
	) {
		std::shared_ptr<GameObject> obj(new GameObject());
		obj->Init(name, xpos, ypos, moveHandle, velocitySetter, sprite, std::move(collider));
		return obj;
	}
};
