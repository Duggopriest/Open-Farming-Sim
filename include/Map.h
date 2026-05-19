#pragma once

#include "include/SDL.h"

class Tile;

class Map
{
	public:
		Map();
		~Map();

		int CCx;
		int CCy;

		bool	loaded;

		void	UnLoadMap(void);

		void	RenderChunks();

		void	updatePlants(bool b);
};

