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
	if (!ChunkMap[y][x].loaded)
	{
		ChunkMap[y][x].x = x;
		ChunkMap[y][x].y = y;
		ChunkMap[y][x].px = x * 5000;
		ChunkMap[y][x].py = y * 5000;
	}
	ChunkMap[y][x].DrawChunk();
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
	
	
	if (!ChunkMap[CCy][CCx].loaded)
	{
		ChunkMap[CCy][CCx].x = CCx;
		ChunkMap[CCy][CCx].y = CCy;
		ChunkMap[CCy][CCx].px = CCx * 25000;
		ChunkMap[CCy][CCx].py = CCy * 25000;
	}
	ChunkMap[CCy][CCx].DrawChunk();
	*/

	
	for (int y = CCy - 1; y <= CCy + 1; y++)
	{
		for (int x = CCx - 1; x <= CCx + 1; x++)
		{
			if (!ChunkMap[y][x].loaded)
			{
				ChunkMap[y][x].x = x;
				ChunkMap[y][x].y = y;
				ChunkMap[y][x].px = x * 5000;
				ChunkMap[y][x].py = y * 5000;
			}
			ChunkMap[y][x].DrawChunk();
		}
	}
	
}
