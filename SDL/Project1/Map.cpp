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

void	Map::updatePlants(bool b)
{
	if (!b)
		return;
	std::map <int, std::map < int, Chunk > >::iterator	itr;
	std::map < int, Chunk >::iterator					ptr;

	for (itr = ChunkMap.begin(); itr != ChunkMap.end(); itr++)
	{
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
		{
			ptr->second.doPlantCal();
			ptr->second.UpdateChunk();
		}
	}
	cout << "plants updated!\n";
}
