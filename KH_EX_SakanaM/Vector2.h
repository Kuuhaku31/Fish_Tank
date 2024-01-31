
#pragma once

#include <cmath>

class Vector2
{   public:
    Vector2(double a = 0.0, double b = 0.0, bool is_use_na = false);

    double _x;
    double _y;
    double _n;
    double _a;

    void ResetX(double x = 0.0);
    void ResetY(double y = 0.0);
    bool ResetN(double n = 1.0);
    void ResetA(double angle = 0.0);
    void ResetV(double a = 0.0, double b = 0.0, bool is_use_na = false);

    Vector2     operator=   (const Vector2& v);
    bool        operator==  (const Vector2& v);
    Vector2     operator+   (const Vector2& v);
    Vector2     operator+=  (const Vector2& v);
    Vector2     operator-   (const Vector2& v);
    Vector2     operator-=  (const Vector2& v);
    Vector2     operator*   (double k);
    Vector2     operator*=  (double k);
    double      operator*   (const Vector2& v);

    void Renew_by_xy();
    void Renew_by_na();
};
