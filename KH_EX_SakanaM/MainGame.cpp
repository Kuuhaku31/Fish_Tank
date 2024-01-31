
#include "MainGame.h"

// ====================================================================================================
// ====================================================================================================
// ====================================================================================================

void 
MainGame::Init()
{
	Init_Graph();
	Init__Bace();
	Initmodule();
}

void 
MainGame::Init_Graph()
{
	initgraph(graph_wide, graph_high, 1);
	setbkcolor(DARKGRAY);
	cleardevice();
}

void 
MainGame::Init__Bace()
{
	library		= new Library();
	input		= new Input();
	main_map	= new Map(); main___map();
	object_01	= new Object(spawn_point);
	main_camera = new Camera(object_01, camera_sight_wide, camera_sight_high, border_thickness, border_thickness);
}

void 
MainGame::main___map()
{
	main_map->Rese(main_paper_wide, main_paper_high);
	main_map->ResetMat(0xcccccc, true);
}

void 
MainGame::Initmodule()
{
	wall = new Map();
	wall->_area = library->GetMap();
	wall->_mat = library->GetWallMat();
	wall->_matLX = -350;
	wall->_matLY = 100;

	ikacyann		= new Object	(Vector2(200, 150), 10);
	ikacyann_coll	= new Collision	(ikacyann, wall, 15.0);
	ikacyann_drag	= new Drag		(ikacyann, friction, friction_m, restitution, restitution_m);
	ika_renderer	= new Renderer	(ikacyann, library->GetIKA(1), library->GetIKA(2));

	main_camera->_obj = ikacyann;
}

// ====================================================================================================
// ====================================================================================================
// ====================================================================================================

bool 
MainGame::Update()
{
	if (!Get_____Input()) { return false; }
	if (!Computational()) { return false; }
	     Update_Screen();   return true;
}

bool 
MainGame::Get_____Input()
{
	input->GetInput();
	if (input->enter) 
	return false;
	return true;
}

bool 
MainGame::Computational()
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	if (input->key_W) { y1 --; }
	if (input->key_S) { y1 ++; }
	if (input->key_A) { x1 --; }
	if (input->key_D) { x1 ++; }

	if (input->arr_U) { y2 --; }
	if (input->arr_D) { y2 ++; }
	if (input->arr_L) { x2 --; }
	if (input->arr_R) { x2 ++; }

	if (input->key_F && button_f == false) 
	{ 
		button_f = true;
		main_camera		->_obj = main_camera	->_obj == ikacyann ? object_01 : ikacyann;
		ika_renderer	->_obj = ika_renderer	->_obj == ikacyann ? object_01 : ikacyann;
	}
	if (!input->key_F && button_f == true) { button_f = false; }

	Vector2 v1(x1, y1);
	Vector2 v2(x2, y2);
	if (v1.ResetN()) { ikacyann->Force(v1 * force); }
	if (v2.ResetN()) { object_01->Move(v2 * 5); }

	ikacyann_coll->Update();
	ikacyann_drag->Update();
	ikacyann->Update();
	object_01->Update();

	Vector2 sp = ikacyann->_p;
	if (!main_map->Isin(sp._x, sp._y)) { return false; }

	return true;
}

void 
MainGame::Update_Screen()
{
	main_map		->ResetMat(C_CCCCC);

	wall			->Draw(&main_map->_mat);
	ikacyann		->Draw(&main_map->_mat, color_01, size_02);
	object_01		->Draw(&main_map->_mat, color_03, size_02);
	ika_renderer	->Draw(&main_map->_mat);

	main_camera		->Photographed(&main_map->_mat);
}

// ====================================================================================================
// ====================================================================================================
// ====================================================================================================

void 
MainGame::Over()
{
	delete library;
	delete input;
	delete main_map;
	delete main_camera;
	delete object_01;
	delete wall;
	delete ika_renderer;
	delete ikacyann_drag;
	delete ikacyann;
}
