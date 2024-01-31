
#pragma once

#include <graphics.h>

#include "Object.h"

class Renderer
{	public:
	Renderer(Object* obj = nullptr, IMAGE image_a = IMAGE(), IMAGE iage_b = IMAGE(), int lx = 0, int ly = 0) :
		_obj(obj),
		_img_a(image_a),
		_img_b(iage_b),
		_lx(lx),
		_ly(ly)
	{}

	Object* _obj;

	IMAGE _img_a;
	IMAGE _img_b;
	int _lx;
	int _ly;

	void 
	Draw(IMAGE* paper) const
	{
		if (_obj == nullptr) { return; }
		SetWorkingImage(paper);
		putimage(_obj->_p._x - _lx, _obj->_p._y - _ly, &_img_b, 0x8800C6);//DSa
		putimage(_obj->_p._x - _lx, _obj->_p._y - _ly, &_img_a, 0xEE0086);//DSo
		SetWorkingImage();
	}

};

