
#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <graphics.h>

//extern IMAGE map_1;
extern std::string path_1_;

//extern IMAGE map_2;
extern std::string path_2_;
extern std::string path_3_;
extern std::string path_4_;
extern std::string data_path_1;
extern std::string data_path_2;

std::array<IMAGE, 2> loadIKA();

HRGN getHRGN();
HRGN getHRGN_();

void saveMap();

std::vector<double> loadData(std::string path);
void saveData(std::string path, std::vector<double> data);

class Library
{
public:
	std::string path = "./Data/Test.txt";

	void OpenFile()
	{
		std::ofstream fout(path);
		if (fout.fail()) { std::cout << "Error opening file" << std::endl; return; }
		fout << "Hello world!!!" << std::endl;
		fout << " 123" << std::endl;
		fout << " 456" << std::endl;
		fout.close();

		std::ifstream fin(path);
		if  (fin.fail()) { std::cout << "Error opening file" << std::endl; return; }
		std::string str;
		while (getline(fin, str))
		{
			std::cout << str << std::endl;
		}
		fin.close();
	}

	std::string main_map_path = "./Material/map - 1.png";
	std::string wall_mat_path = "./Material/wall_mat.png";
	std::string ika_a_path = "./Material/ika_a.png";
	std::string ika_b_path = "./Material/ika_b.png";

	IMAGE GetMap()
	{
		IMAGE map;
		loadimage(&map, main_map_path.c_str());
		return map;
	}

	IMAGE GetWallMat()
	{
		IMAGE wall_mat;
		loadimage(&wall_mat, wall_mat_path.c_str());
		return wall_mat;
	}

	IMAGE GetIKA(int n)
	{
		IMAGE ika;
		if (n == 1) { loadimage(&ika, ika_a_path.c_str()); }
		else		{ loadimage(&ika, ika_b_path.c_str()); }
		return ika;
	}
};
