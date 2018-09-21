#include "Physics.h"

void ConstVelocitySetter::update(GameObject * obj) {
	static float sqrt2 = sqrt(2);
	switch (obj->dir)
	{
	case(NONE):
		break;
	case(UP):
		obj->ypos += speed;
		break;
	case(DOWN):
		obj->ypos -= speed;
		break;
	case(LEFT):
		obj->xpos -= speed;
		break;
	case(RIGHT):
		obj->xpos += speed;
		break;
	case(UP_LEFT):
		obj->xpos -= speed * sqrt2;
		obj->ypos += speed * sqrt2;
		break;
	case(UP_RIGHT):
		obj->xpos += speed * sqrt2;
		obj->ypos += speed * sqrt2;
		break;
	case(DOWN_LEFT):
		obj->xpos -= speed * sqrt2;
		obj->ypos -= speed * sqrt2;
		break;
	case(DOWN_RIGHT):
		obj->xpos += speed * sqrt2;
		obj->ypos -= speed * sqrt2;
		break;
	default:
		break;
	}
	return;
}
