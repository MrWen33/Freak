#include "Physics.h"

ConstVelocitySetter::ConstVelocitySetter(float Speed) :
	horizontal_speed(Speed),
	vertical_speed(Speed*WindowInfo::width / WindowInfo::height) {}

void ConstVelocitySetter::update(GameObject * obj) {
	static float sqrt2 = sqrt(2);
	switch (obj->dir)
	{
	case(NONE):
		break;
	case(UP):
		obj->ypos += vertical_speed;
		break;
	case(DOWN):
		obj->ypos -= vertical_speed;
		break;
	case(LEFT):
		obj->xpos -= horizontal_speed;
		break;
	case(RIGHT):
		obj->xpos += horizontal_speed;
		break;
	case(UP_LEFT):
		obj->xpos -= horizontal_speed/sqrt2;
		obj->ypos += vertical_speed/ sqrt2;
		break;
	case(UP_RIGHT):
		obj->xpos += horizontal_speed / sqrt2;
		obj->ypos += vertical_speed / sqrt2;
		break;
	case(DOWN_LEFT):
		obj->xpos -= horizontal_speed / sqrt2;
		obj->ypos -= vertical_speed / sqrt2;
		break;
	case(DOWN_RIGHT):
		obj->xpos += horizontal_speed / sqrt2;
		obj->ypos -= vertical_speed / sqrt2;
		break;
	default:
		break;
	}
	return;
}
