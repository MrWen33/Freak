#pragma once

#include"GameObject.h"
#include<cmath>
#include<tuple>
class GameObject;

template <class T>
class Bound {
public:
	Bound(T xcenter = 0, T ycenter = 0, T width = 0, T height = 0)
	{
		this->xcenter = xcenter;
		this->ycenter = xcenter;
		this->width = width;
		this->height = height;
		isChanged = true;
	}
	void clamp(T&x, T&y){
		update();
		if (x < xmin) x = xmin;
		else if (x > xmax) x = xmax;
		if (y < ymin) y = ymin;
		else if (y > ymax) y = ymax;
	}
	void update(){
		if (isChanged) {
			xmin = xcenter - width / 2;
			xmax = xcenter + width / 2;
			ymin = ycenter - height / 2;
			ymax = ycenter + height / 2;
			isChanged = false;
		}
	}
	void setCenter(T xcenter, T ycenter) {
		this->xcenter = xcenter;
		this->ycenter = ycenter;
		isChanged = true;
	}
	void setWidth(T wid) {
		width = wid;
		isChanged = true;
	}
	void setHeight(T height) {
		this->height = height;
		isChanged = true;
	}
	std::tuple<T, T> getCenter() {
		update();
		return std::make_tuple(xcenter, ycenter);
	}
	std::tuple<T, T, T, T> getBound() {
		update();
		return std::make_tuple(xmin, xmax, ymin, ymax);
	}
	std::tuple<T, T> getRect() {
		update();
		return std::make_tuple(width, height);
	}
	Bound<T> Union(Bound<T>& other) {
		auto other_bound = other.getBound();
		auto this_bound = getBound();
		
		T newXmin = std::fmin(std::get<0>(other_bound), std::get<0>(this_bound));
		T newXmax = std::fmax(std::get<1>(other_bound), std::get<1>(this_bound));
		T newYmin = std::fmin(std::get<2>(other_bound), std::get<2>(this_bound));
		T newYmax = std::fmax(std::get<3>(other_bound), std::get<3>(this_bound));
		return Bound<T>((newXmin+newXmax)/2.f, (newYmin + newYmax) / 2.f, newXmax-newXmin, newYmax-newYmin);
	}
private:
	T xmin, xmax, ymin, ymax;
	T xcenter, ycenter;
	T width, height;
	bool isChanged;
};
typedef Bound<float> Bound2f;


class BoxCollider{
public:
	BoxCollider(Bound2f bound) :bound(bound) {};
	bool isCollisionWith(BoxCollider* other);
	void update(GameObject* father);
private:
	Bound2f bound;
};

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