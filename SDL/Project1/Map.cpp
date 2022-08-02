#include "Map.h"
#include "PerlinNoise.h"
#include <thread>

Map::Map(void)
{
	CCx = 0;
	CCy = 0;
	loaded = false;
}

Map::~Map(void)
{
	
}

void	Map::LoadMap(const char* name)
{
}

void	Map::UnLoadMap(void)
{
	loaded = false;
}


void Map::WriteMap(const char* name)
{

}

void	doChunk(int y, int x)
{
	if (!Chunk_Map[y][x].loaded)
	{
		Chunk_Map[y][x].x = x;
		Chunk_Map[y][x].y = y;
		Chunk_Map[y][x].px = x * 5000;
		Chunk_Map[y][x].py = y * 5000;
	}
	Chunk_Map[y][x].DrawChunk();
}

void	Map::RenderChunks()
{
	CCx = floor((double)player.x / 5000);
	CCy = floor((double)player.y / 5000);


	/*
	std::thread TThread[9];

	char i = 0;

	for (int y = CCy - 1; y <= CCy + 1; y++)
	{
		for (int x = CCx - 1; x <= CCx + 1; x++)
		{
			TThread[i++] = std::thread(doChunk, y, x);
		}
	}

	for (char j = 0; j < 9; j++)
	{
		TThread[j].join();
	}
	
	
	if (!Chunk_Map[CCy][CCx].loaded)
	{
		Chunk_Map[CCy][CCx].x = CCx;
		Chunk_Map[CCy][CCx].y = CCy;
		Chunk_Map[CCy][CCx].px = CCx * 25000;
		Chunk_Map[CCy][CCx].py = CCy * 25000;
	}
	Chunk_Map[CCy][CCx].DrawChunk();
	*/

	
	for (int y = CCy - 1; y <= CCy + 1; y++)
	{
		for (int x = CCx - 1; x <= CCx + 1; x++)
		{
			if (!Chunk_Map[y][CCx].loaded)
			{
				Chunk_Map[y][x].x = x;
				Chunk_Map[y][x].y = y;
				Chunk_Map[y][x].px = x * 5000;
				Chunk_Map[y][x].py = y * 5000;
			}
			Chunk_Map[y][x].DrawChunk();
		}
	}
	
}
