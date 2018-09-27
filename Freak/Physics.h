#pragma once

#include"GameObject.h"
class GameObject;

template <class T>
struct Bound {
	T xmin, xmax, ymin, ymax;
	Bound(T xmin = 0, T xmax = 0, T ymin = 0, T ymax = 0) :xmin(xmin), xmax(xmax), ymin(ymin), ymax(ymax) {}
	void clamp(T&x, T&y) {
		if (x < xmin) x = xmin;
		else if (x > xmax) x = xmax;
		if (y < ymin) y = ymin;
		else if (y > ymax) y = ymax;
	}
};
typedef Bound<float> Bound2f;

class VelocitySetter {
public:
	virtual void update(GameObject*) = 0;
	virtual ~VelocitySetter() {}
};

class ConstVelocitySetter: public VelocitySetter {
private:
	const float horizontal_speed;
	const float vertical_speed;
	Bound2f bound;
	bool bound_isset;
public:
	ConstVelocitySetter(float Speed);
	void setBound(Bound2f bound) {
		this->bound = bound;
		bound_isset = true;
	}
	void update(GameObject* obj) override;
};