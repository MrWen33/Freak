#include "Physics.h"
#include "utils.h"

ConstVelocitySetter::ConstVelocitySetter(float Speed) :
	horizontal_speed(Speed),
	vertical_speed(Speed*WindowInfo::width / WindowInfo::height),
	bound_isset(false){}

void ConstVelocitySetter::update(GameObject * obj) {
	static float sqrt2 = sqrt(2);
	switch (obj->live.dir)
	{
	case(NONE):
		break;
	case(UP):
		obj->live.ypos += vertical_speed;
		break;
	case(DOWN):
		obj->live.ypos -= vertical_speed;
		break;
	case(LEFT):
		obj->live.xpos -= horizontal_speed;
		break;
	case(RIGHT):
		obj->live.xpos += horizontal_speed;
		break;
	case(UP_LEFT):
		obj->live.xpos -= horizontal_speed/sqrt2;
		obj->live.ypos += vertical_speed/ sqrt2;
		break;
	case(UP_RIGHT):
		obj->live.xpos += horizontal_speed / sqrt2;
		obj->live.ypos += vertical_speed / sqrt2;
		break;
	case(DOWN_LEFT):
		obj->live.xpos -= horizontal_speed / sqrt2;
		obj->live.ypos -= vertical_speed / sqrt2;
		break;
	case(DOWN_RIGHT):
		obj->live.xpos += horizontal_speed / sqrt2;
		obj->live.ypos -= vertical_speed / sqrt2;
		break;
	default:
		break;
	}
	if (bound_isset) {
		bound.clamp(obj->live.xpos, obj->live.ypos);
	}
	return;
}

bool BoxCollider::isCollisionWith(BoxCollider * other)
{
	Bound2f new_bound = bound.Union(other->bound);
	auto this_rect = bound.getRect();
	auto other_rect = other->bound.getRect();
	auto new_rect = new_bound.getRect();
	float wid_sum = std::get<0>(this_rect) + std::get<0>(other_rect);
	float height_sum = std::get<1>(this_rect) + std::get<1>(other_rect);
	return (wid_sum > std::get<0>(new_rect) && height_sum > std::get<1>(new_rect));
}
