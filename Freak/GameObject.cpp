#include"GameObject.h"

std::vector<GameObject *> GameObject::objects = std::vector<GameObject *>();
bool GameObject::should_fresh = false;

void GameObject::fresh_obj_sheet() {
	if (!should_fresh) return;
	for (int i = objects.size() - 1; i >= 0; --i) {
		if (objects[i] == NULL) {
			objects.erase(objects.begin() + i);
		}
	}
	should_fresh = false;
}

GameObject::GameObject(std::string name, MoveHandle * moveHandle, VelocitySetter * velocitySetter, Sprite * sprite)
{
	this->name = name;
	this->moveHandle = moveHandle;
	this->velocitySetter = velocitySetter;
	this->sprite = sprite;
	objects.push_back(this);
	xpos = 0;
	ypos = 0;
}

inline void GameObject::Draw() {

	if (sprite != NULL) sprite->Draw(*this);
}

inline void GameObject::Update(float deltaTime) {
	if (moveHandle != NULL) moveHandle->update(this);
	if (velocitySetter != NULL) velocitySetter->update(this);
}

inline GameObject::~GameObject() {
	auto this_iter = std::find(objects.begin(), objects.end(), this);
	*this_iter = NULL;
	should_fresh = true;
}
