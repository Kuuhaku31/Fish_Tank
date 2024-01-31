
#pragma once

#include "Object.h"
#include "Area.h"

class Collision
{	public:
	Collision(Object* obj = nullptr, Area* area = nullptr, double size = 0.0) :
		_obj(obj),
		_area(area),
		_size(size)
	{}

	Object* _obj;
	Area* _area;

	double _size;

	void Update()
	{
		Vector2 v;
		for (int i = 0; i < 12; i++)
		{
			bool is_in; TestPoint* tp; switch (i)
			{
				case  0: tp = &_tp00; break;
				case  1: tp = &_tp01; break;
				case  2: tp = &_tp02; break;
				case  3: tp = &_tp03; break;
				case  4: tp = &_tp04; break;
				case  5: tp = &_tp05; break;
				case  6: tp = &_tp06; break;
				case  7: tp = &_tp07; break;
				case  8: tp = &_tp08; break;
				case  9: tp = &_tp09; break;
				case 10: tp = &_tp10; break;
				case 11: tp = &_tp11; break;
				default: tp =nullptr; break;
			}
			if (_area->Isin(_obj->_p._x + tp->_dx, _obj->_p._y + tp->_dy)) { v._x -= tp->_ax, v._y -= tp->_ay; }
		}
		v.Renew_by_xy();
		if (v.ResetN())	{_obj->_v += v * abs(_obj->_v * v) * 1.1; }
	}

private:
	double PI = 3.1415926535897932384626433832795;

	class TestPoint
	{	public:
		TestPoint(Vector2 dp, double angle) : 
			_dx(dp._x),
			_dy(dp._y),
			_ax(cos(angle)),
			_ay(sin(angle))
		{}

		double _dx;
		double _dy;
		double _ax;
		double _ay;
	};

	const double angle_00 = PI *  0.0 / 6.0;
	const double angle_01 = PI *  1.0 / 6.0;
	const double angle_02 = PI *  2.0 / 6.0;
	const double angle_03 = PI *  3.0 / 6.0;
	const double angle_04 = PI *  4.0 / 6.0;
	const double angle_05 = PI *  5.0 / 6.0;
	const double angle_06 = PI *  6.0 / 6.0;
	const double angle_07 = PI *  7.0 / 6.0;
	const double angle_08 = PI *  8.0 / 6.0;
	const double angle_09 = PI *  9.0 / 6.0;
	const double angle_10 = PI * 10.0 / 6.0;
	const double angle_11 = PI * 11.0 / 6.0;

	TestPoint _tp00 = TestPoint(Vector2(_size, angle_00, true), angle_00);
	TestPoint _tp01 = TestPoint(Vector2(_size, angle_01, true), angle_01);
	TestPoint _tp02 = TestPoint(Vector2(_size, angle_02, true), angle_02);
	TestPoint _tp03 = TestPoint(Vector2(_size, angle_03, true), angle_03);
	TestPoint _tp04 = TestPoint(Vector2(_size, angle_04, true), angle_04);
	TestPoint _tp05 = TestPoint(Vector2(_size, angle_05, true), angle_05);
	TestPoint _tp06 = TestPoint(Vector2(_size, angle_06, true), angle_06);
	TestPoint _tp07 = TestPoint(Vector2(_size, angle_07, true), angle_07);
	TestPoint _tp08 = TestPoint(Vector2(_size, angle_08, true), angle_08);
	TestPoint _tp09 = TestPoint(Vector2(_size, angle_09, true), angle_09);
	TestPoint _tp10 = TestPoint(Vector2(_size, angle_10, true), angle_10);
	TestPoint _tp11 = TestPoint(Vector2(_size, angle_11, true), angle_11);
};
