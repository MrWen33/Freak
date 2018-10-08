#include "Physics.h"
#include "utils.h"

ConstVelocitySetter::ConstVelocitySetter(float Speed) :
	horizontal_speed(Speed),
	vertical_speed(Speed*WindowInfo::width / WindowInfo::height),
	bound_isset(false){}

void ConstVelocitySetter::update(GameObject * obj) {
	static float sqrt2 = sqrt(2);
	auto origin_pos = obj->getPos();
	switch (obj->getDir())
	{
	case(NONE):
		break;
	case(UP):
		obj->setPos(origin_pos.x, origin_pos.y + vertical_speed);
		break;
	case(DOWN):
		obj->setPos(origin_pos.x, origin_pos.y - vertical_speed);
		break;
	case(LEFT):
		obj->setPos(origin_pos.x - horizontal_speed, origin_pos.y);
		break;
	case(RIGHT):
		obj->setPos(origin_pos.x + horizontal_speed, origin_pos.y); 
		break;
	case(UP_LEFT):
		obj->setPos(origin_pos.x - horizontal_speed/sqrt2, origin_pos.y + vertical_speed / sqrt2);
		break;
	case(UP_RIGHT):
		obj->setPos(origin_pos.x + horizontal_speed / sqrt2, origin_pos.y + vertical_speed / sqrt2);
		break;
	case(DOWN_LEFT):
		obj->setPos(origin_pos.x - horizontal_speed / sqrt2, origin_pos.y - vertical_speed / sqrt2);
		break;
	case(DOWN_RIGHT):
		obj->setPos(origin_pos.x + horizontal_speed / sqrt2, origin_pos.y - vertical_speed / sqrt2); 
		break;
	default:
		break;
	}
	if (bound_isset) {
		auto now_pos = obj->getPos();
		bound.clamp(now_pos.x, now_pos.y);
		obj->setPos(now_pos.x, now_pos.y);
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

void BoxCollider::update(GameObject * father)
{
	auto pos = father->getPos();
	bound.setCenter(pos.x, pos.y);
}
