#pragma once

#include"GameObject.h"
class GameObject;

class VelocitySetter {
public:
	virtual void update(GameObject*) = 0;
	virtual ~VelocitySetter() {}
};

class ConstVelocitySetter: public VelocitySetter {
private:
	const float horizontal_speed;
	const float vertical_speed;
public:
	ConstVelocitySetter(float Speed);
	void update(GameObject* obj) override;
};