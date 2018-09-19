#include"GameObject.h"

std::vector<GameObject *> GameObject::objects = std::vector<GameObject *>();
bool GameObject::should_fresh = false;