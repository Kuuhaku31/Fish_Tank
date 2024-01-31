
#pragma once

#include <graphics.h>

#include "Colors.h"
#include "Library.h"
#include "Input.h"
#include "Map.h"
#include "Camera.h"
#include "Renderer.h"
#include "Drag.h"
#include "Collision.h"

class MainGame
{	public:

	void 
	Run()
	{
		Init();

		DWORD start_time = 0;
		DWORD end___time = 0;
		DWORD delta_time = 0;

		BeginBatchDraw();
		do
		{
			FlushBatchDraw();
			end___time = clock();
			delta_time = end___time - start_time; //std::cout << delta_time << std::endl;
			if (delta_time < 1000 / frame_rate) { Sleep(1000 / frame_rate - delta_time); }
			start_time = clock();
		} while (Update());
		EndBatchDraw();

		Over();
	}

private:

	int frame_rate = 60;
	int graph_wide = 1600;
	int graph_high = 900;

	int main_paper_wide = 1000;
	int main_paper_high = 1000;

	int border_thickness = 10;
	int camera_sight_wide = graph_wide - border_thickness * 2;
	int camera_sight_high = graph_high - border_thickness * 2;

	Vector2 spawn_point = Vector2(200, 100);

	double force = 500.0;
	double friction = 50.0;//5.0, 2.0, 0.1, 0.1);
	double friction_m = 0.1;
	double restitution = 0.1;
	double restitution_m = 0.1;

	int color_01 = BGR(C___IKA);
	int color_02 = GREEN;
	int color_03 = BLUE;

	int size_01 = 1;
	int size_02 = 5;
	int size_03 = 10;

	//====================================================================================================
	Library*	library			= nullptr;
	Input*		input			= nullptr;
	Map*		main_map		= nullptr;
	Object*		object_01		= nullptr;
	Camera*		main_camera		= nullptr;

	Map*		wall			= nullptr;
	Object*		ikacyann		= nullptr;
	Collision*	ikacyann_coll	= nullptr;
	Drag*		ikacyann_drag	= nullptr;
	Renderer*	ika_renderer	= nullptr;

	bool button_f = false;
	
	void Init();
	void Init_Graph();
	void Init__Bace();
	void main___map();
	void Initmodule();

	bool Update();
	bool Get_____Input();
	bool Computational();
	void Update_Screen();
	
	void Over();
};
