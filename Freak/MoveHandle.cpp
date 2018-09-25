#include "MoveHandle.h"

void InputMovement::update(GameObject * obj) {
	unsigned int key = 0;//代表上下左右是否按下
	if (glfwGetKey(WindowInfo::window, GLFW_KEY_W) == GLFW_PRESS) {
		key += 1;
	}
	if (glfwGetKey(WindowInfo::window, GLFW_KEY_S) == GLFW_PRESS) {
		key += 1<<1;
	}
	if (glfwGetKey(WindowInfo::window, GLFW_KEY_A) == GLFW_PRESS) {
		key += 1<<2;
	}
	if (glfwGetKey(WindowInfo::window, GLFW_KEY_D) == GLFW_PRESS) {
		key += 1<<3;
	}
	switch (key)
	{
	case(1):
		obj->live.dir = UP;
		break;
	case(1<<1):
		obj->live.dir = DOWN;
		break;
	case(1 << 2):
		obj->live.dir = LEFT;
		break;
	case(1 << 3):
		obj->live.dir = RIGHT;
		break;
	case(1 + (1<<3)):
		obj->live.dir = UP_RIGHT;
		break;
	case(1 + (1<<2)):
		obj->live.dir = UP_LEFT;
		break;
	case((1<<1) + (1<<3)):
		obj->live.dir = DOWN_RIGHT;
		break;
	case((1<<1) + (1<<2)):
		obj->live.dir = DOWN_LEFT;
		break;
	default:
		obj->live.dir = NONE;
		break;
	}
}
