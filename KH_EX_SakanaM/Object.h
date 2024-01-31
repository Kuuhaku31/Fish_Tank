
#pragma once

#include <graphics.h>

#include "Vector2.h"

class Object
{	public:
	Object(Vector2 p, double m = 0.0, double dt = 0.1) :
		DT(dt), 
		_m(m),
		_p(p),
		_v(Vector2(0.0, 0.0)),
		_a(Vector2(0.0, 0.0))
	{}

	double   DT;
	double   _m;
	Vector2  _p;
	Vector2  _v;
	Vector2  _a;

	void 
	Move	(Vector2 dp) { _p += dp; }

	void 
	Force	(Vector2 force, bool is_ignore_mass = false)
	{
		if (is_ignore_mass || _m == 0.0) { _a += force; return; }
		_a += force * (1 / _m);
	}

	virtual void 
	Update	()
	{
		_p += _v * DT;
		_v += _a * DT;
		_a *= 0.0;
	}

	virtual void 
	Draw	(IMAGE* paper, int color, int r) const
	{
		SetWorkingImage(paper);
		setfillcolor(color);
		solidcircle(_p._x, _p._y, r);
		SetWorkingImage();
	}
};
