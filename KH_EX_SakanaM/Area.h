
#pragma once

#include <graphics.h>

class Area
{
public:
	IMAGE _area;
	int _wx = 0;
	int _wy = 0;

	bool 
	Isin(int x, int y, bool use_local = false)
	{
		if (!use_local) { Isin(x - _wx, y - _wy, true); }
		SetWorkingImage(&_area);
		int c = getpixel(x, y);
		SetWorkingImage();
		if (c == 0xffffff) return true; return false;
	}

	virtual void 
	Draw(IMAGE* paper) const
	{
		SetWorkingImage(paper);
		putimage(_wx, _wy, &_area, 0x220326);//DSna
		putimage(_wx, _wy, &_area, 0xEE0086);//DSo
		SetWorkingImage();
	}

	virtual void 
	Rese(int w, int h, bool all_clear = false)
	{
		_area.Resize(w, h);
		SetWorkingImage(&_area);
		int c = all_clear ? 0x000000 : 0xffffff;
		setbkcolor(c);
		cleardevice();
		SetWorkingImage();
	}

	void 
	Reverse()
	{
		SetWorkingImage(&_area);
		putimage(0, 0, &_area, 0x550009);//Dn
		SetWorkingImage();
	}

};

