
#include <conio.h>

#include "MainGame.h"

void 
Fun_0()
{
	MainGame game;
	game.Run();
}

void 
Fun_1()
{
	initgraph(700, 600, 1);

	IMAGE paper(500, 500);
	SetWorkingImage(&paper);
	setbkcolor(0xcccccc);
	cleardevice();
	SetWorkingImage();

	IMAGE area_1(150, 150);
	SetWorkingImage(&area_1);
	setfillcolor(0xffffff);
	solidrectangle(20, 120, 100, 100);
	fillcircle(50, 50, 20);
	line(0, 0, 150, 0);
	SetWorkingImage();

	IMAGE mat(200, 200);
	SetWorkingImage(&mat);
	setbkcolor(BLUE);
	cleardevice();
	SetWorkingImage();

	putimage(20, 30, &paper);

	char c = _getch();
	closegraph();
}

void 
Fun_2()
{
	Library lib;
	lib.OpenFile();
}

int 
main()
{
	std::cout << "GAME START" << std::endl;
	Fun_0();
	std::cout << "GAME OVER!" << std::endl;
	return 0;
}
