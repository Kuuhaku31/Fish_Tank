
#include "Vector2.h"

Vector2::Vector2(double a, double b, bool is_use_na)
{
    if (is_use_na)
    {
        _n = a;
        _a = b;
        Renew_by_na();
        return;
	}
    _x = a;
    _y = b;
    Renew_by_xy();
}

void 
Vector2::ResetX(double x) { _x = x; Renew_by_xy(); }

void 
Vector2::ResetY(double y) { _y = y; Renew_by_xy(); }

bool
Vector2::ResetN(double n) 
{
    if (_n == 0.0)  { return false; }
    if (n < 0.0)    { _a = std::atan2(-_y, -_x); _n = -n;   Renew_by_na(); }
    else            { _n = n;                               Renew_by_na(); }
    return true;
}

void
Vector2::ResetA(double angle)
{
    if (_n != 0.0)
    {
        _a = angle;
		Renew_by_xy();
    }
}

void Vector2::ResetV(double a, double b, bool is_use_na)
{
    if (is_use_na)
    {
		_n = a;
		_a = b;
		Renew_by_na();
		return;
	}
	_x = a;
	_y = b;
	Renew_by_xy();
}

void 
Vector2::Renew_by_xy()
{
    _n = std::sqrt(_x * _x + _y * _y);
    _a = std::atan2(_y, _x);
}

void 
Vector2::Renew_by_na()
{
    _x = _n * std::cos(_a);
    _y = _n * std::sin(_a);
}

Vector2 
Vector2::operator=(const Vector2& v)
{
    _x = v._x;
    _y = v._y;
    _n = v._n;
    _a = v._a;
    return *this;
}

bool 
Vector2::operator==(const Vector2& v)
{
    if (_x == v._x && _y == v._y) { return true; }
    return false;
}

Vector2 
Vector2::operator+(const Vector2 &v) 
{
    Vector2 res;
    res._x = _x + v._x;
    res._y = _y + v._y;
    res.Renew_by_xy();
    return res;
}

Vector2 
Vector2::operator+=(const Vector2& v)
{
    _x += v._x;
    _y += v._y;
    Renew_by_xy();
    return *this;
}

Vector2
Vector2::operator-(const Vector2 &v) 
{
    Vector2 res;
    res._x = _x - v._x;
    res._y = _y - v._y;
    res.Renew_by_xy();
    return res;
}

Vector2 Vector2::operator-=(const Vector2& v)
{
    _x -= v._x;
    _y -= v._y;
    Renew_by_xy();
    return *this;
}

Vector2 Vector2::operator*(double k) 
{
    Vector2 res;
    res._x = _x * k;
    res._y = _y * k;
    Renew_by_xy();
    return res;
}

Vector2 Vector2::operator*=(double k)
{
    _x *= k;
    _y *= k;
    Renew_by_xy();
    return *this;
}

double Vector2::operator*(const Vector2& v)
{
    return _x * v._x + _y * v._y;
}
