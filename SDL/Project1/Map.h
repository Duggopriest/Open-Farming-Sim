#pragma once

#include <SDL.h>

class Tile;

class Map
{
	public:
		Map();
		~Map();

		int CCx;
		int CCy;

		bool	loaded;

		void	LoadMap(const char* name);
		void	UnLoadMap(void);

		void	WriteMap(const char* name);//ToDo

		void	RenderChunks();

		void	updatePlants(bool b);
};

