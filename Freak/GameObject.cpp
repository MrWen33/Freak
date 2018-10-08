#include"GameObject.h"
#include"utils.h"
void GameObject::Draw() {

	if (sprite != NULL) sprite->Draw(*this);
}

bool GameObject::isMove()
{
	return dir != NONE;
}

bool GameObject::Update(float deltaTime) {
	if(moveHandle) moveHandle->update(this);
	if(velocitySetter) velocitySetter->update(this);
	return true;
}

void GameObject::Init(std::string name, float xpos, float ypos, 
	std::shared_ptr<MoveHandle> moveHandle,
	std::shared_ptr<VelocitySetter> velocitySetter,
	std::shared_ptr<Sprite> sprite, 
	std::unique_ptr<BoxCollider> collider)
{
	this->name = name;
	this->setPos(xpos, ypos);
	this->moveHandle = moveHandle;
	this->velocitySetter = velocitySetter;
	this->sprite = sprite;
	this->collider = std::move(collider);
}

void GameObject::OnCollisionWith(GameObject & other)
{
	//std::cout << "BOOM!" << std::endl;
}

bool GameObject::IsCollisionWith(GameObject & other)
{
	BoxCollider* this_collider = GetWorldCollider();
	BoxCollider* other_collider = other.GetWorldCollider();
	if (this_collider&&other_collider) {
		
		return this_collider->isCollisionWith(other_collider);
	}
	return false;
}


BoxCollider* GameObject::GetWorldCollider()
{
	if (collider) {
		collider->update(this);
		return collider.get();
	}
	return NULL;
}

GameObject::GameObject() {
}