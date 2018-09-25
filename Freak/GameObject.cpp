#include"GameObject.h"

inline void GameObject::Draw() {

	if (live.sprite != NULL) live.sprite->Draw(*this);
}

bool GameObject::Update(float deltaTime) {
	if (!IsInUse()) return false;
	if (live.moveHandle != NULL) live.moveHandle->update(this);
	if (live.velocitySetter != NULL) live.velocitySetter->update(this);
	if (abs(live.xpos) > 1.3 || abs(live.ypos) > 1.3) {
		in_use = false;
		return true;
	};
	Draw();
	return false;
}

void GameObject::Init(std::string name, MoveHandle * moveHandle, VelocitySetter * velocitySetter, Sprite * sprite)
{
	live.name = name;
	live.moveHandle = moveHandle;
	live.velocitySetter = velocitySetter;
	live.sprite = sprite;
	live.xpos = 0;
	live.ypos = 0;
	in_use = true;
}

bool GameObject::IsInUse()
{
	return in_use;
}

GameObject::GameObject() {
	in_use = false;
}

GameObjectPool::GameObjectPool()
{
	first_avaliable = &objs[0];
	for (int i = 0; i < POOL_SIZE-1; ++i) {
		objs[i].next = &objs[i + 1];
	}
}

void GameObjectPool::create(std::string name, MoveHandle * moveHandle, VelocitySetter * velocitySetter, Sprite * sprite)
{
	GameObject* next_first_avaliable = first_avaliable->GetNext();
	first_avaliable->Init(name, moveHandle, velocitySetter, sprite);
	first_avaliable = next_first_avaliable;
}

void GameObjectPool::update(float deltaTime)
{
	for (auto& obj : objs) {
		if (obj.Update(deltaTime)) {
			obj.SetNext(first_avaliable);
			first_avaliable = &obj;
		}
	}
}
