#pragma once

template<class T>
class RAII {
public:
	RAII(T* resource) {
		res = resource;
	}
	~RAII() {
		delete res;
	}
	T* get() {
		return res;
	}
private:
	RAII(const RAII&);
	T* res;
};