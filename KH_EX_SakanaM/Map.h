
#pragma once

#include "Area.h"

class Map : public Area
{
public:
	IMAGE _mat;
	int _matLX = 0;
	int _matLY = 0;

	void 
	Draw(IMAGE* paper) const override
	{
		IMAGE _img = _area;
		SetWorkingImage(&_img);
		putimage(_matLX, _matLY, &_mat, 0x8800C6);//DSa

		SetWorkingImage(paper);
		putimage(_wx, _wy, &_area, 0x220326);//DSna
		putimage(_wx, _wy, &_img, 0xEE0086);//DSo
		SetWorkingImage();
	}

	void 
	ResetMat(int c, bool is_reset_size = false)
	{
		if (c == -1) { _mat.Resize(0, 0); return; }
		if (is_reset_size) { _mat.Resize(_area.getwidth(), _area.getheight()); }
		SetWorkingImage(&_mat);
		setbkcolor(c);
		cleardevice();
		SetWorkingImage();
	}

};

