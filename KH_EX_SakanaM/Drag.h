
#pragma once

#include "Object.h"

class Drag
{
public:
	Drag(Object* obj = nullptr, double u = 0.0, double f = 0.0, double c = 0.0, double r = 0.0) :
		_obj(obj),
		_u(u),
		_f(f),
		_c(c),
		_r(r)
	{}

	Object* _obj;

	double _u;
	double _f;
	double _c;
	double _r;

	void Update(bool is_ignore_mass = false)
	{
		if (_obj == nullptr) { return; }
		double d1 = _u;
		double d2 = (_obj->_v._n) * (_obj->_v._n) * _c;
		if (!is_ignore_mass && !_obj->_m == 0.0) { d1 *= (_f / _obj->_m); d2 *= (_r / _obj->_m); }
		double n = _obj->_v._n - d1 - d2;

		if (n < 0.0) { _obj->_v.ResetV(); return; }
		_obj->_v.ResetN(n);
	}

	void Update_Frict(bool is_ignore_mass = false)
	{
		if (_obj == nullptr) { return; }
		double d = _u;
		if (!is_ignore_mass && !_obj->_m == 0.0) { d *= (_f / _obj->_m); }
		double n = _obj->_v._n - d;

		if (n < 0.0) { _obj->_v.ResetV(); return; }
		_obj->_v.ResetN(n);
	}

	void Update_Resist(bool is_ignore_mass = false)
	{
		if (_obj == nullptr) { return; }
		double d = (_obj->_v._n) * (_obj->_v._n) * _c;
		if (!is_ignore_mass && !_obj->_m == 0.0) { d *= (_r / _obj->_m); }
		double n = _obj->_v._n - d;

		if (n < 0.0) { _obj->_v.ResetV(); return; }
		_obj->_v.ResetN(n);
	}
};
