
#pragma once

#include "Object.h"

class Camera
{
public:
	Camera(Object* obj = nullptr , int sight_widh = 0, int sight_high = 0, int gx = 0, int gy = 0) :
		_obj(obj),
		_sight(IMAGE(sight_widh, sight_high)),
		_gx(gx),
		_gy(gy)
	{ _dv = Vector2(-sight_widh, -sight_high) * 0.5; }

	Object* _obj;

	IMAGE _sight;
	Vector2 _dv;
	int _gx;
	int _gy;

	bool Photographed(const IMAGE* paper)
	{
		if (_obj == nullptr) { return false; }
		SetWorkingImage(&_sight);
		setbkcolor(0x000000);
		cleardevice();
		putimage(-_obj->_p._x - _dv._x, -_obj->_p._y - _dv._y, paper);
		SetWorkingImage();
		putimage(_gx, _gy, &_sight);
		return true;
	}
};
