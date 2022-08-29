#include "Item.h"
#include "Header.hpp"

Item::Item()
{
	m_id = 0;
	m_name = "";
	m_stackable = 1;
	m_quanity = 0;
	m_classType = 0;
}

Item& Item::operator=(const Item& src)
{
	*this = src;
	return (*this);
}

void	Item::doClick(int x, int y)
{
	cout << "Default item click\n";
}


// =================================================================== Plow Item 
Plow_Item::Plow_Item()
{
	m_id = 1;
	m_name = "Plow";
	m_quanity = 1;
	m_classType = 't';
}

void Plow_Item::doClick(int x, int y)
{
	int	ww = WINDOW_WIDTH / 2;
	int	wh = WINDOW_HEIGHT / 2;

	int	Cx, Cy, Tx, Ty;

	Cx = floor((double)((player.x * ZOOM) + x + -(WINDOW_WIDTH / 2)) / (ZOOM * 100));
	Cy = floor((double)((player.y * ZOOM) + y + -(WINDOW_HEIGHT / 2)) / (ZOOM * 100));

	Chunk& CC = ChunkMap[Cy][Cx];

	Tx = (int)floor((double)((player.x * ZOOM) + x + -ww) / (ZOOM)) % 100;
	Ty = (int)floor((double)((player.y * ZOOM) + y + -wh) / (ZOOM)) % 100;

	if (Tx < 0)
		Tx += 100;
	if (Ty < 0)
		Ty += 100;

	CC.PlantMap[Ty][Tx] = Plant();
	CC.UpdateChunk();

}


// =================================================================== Scythe Item 
Scythe_Item::Scythe_Item()
{
	m_id = 2;
	m_name = "Scythe";
	m_quanity = 1;
	m_classType = 't';
}

void Scythe_Item::doClick(int x, int y)
{
	int	ww = WINDOW_WIDTH / 2;
	int	wh = WINDOW_HEIGHT / 2;

	int	Cx, Cy, Tx, Ty;

	Cx = floor((double)((player.x * ZOOM) + x + -(WINDOW_WIDTH / 2)) / (ZOOM * 100));
	Cy = floor((double)((player.y * ZOOM) + y + -(WINDOW_HEIGHT / 2)) / (ZOOM * 100));

	Chunk& CC = ChunkMap[Cy][Cx];

	Tx = (int)floor((double)((player.x * ZOOM) + x + -ww) / (ZOOM)) % 100;
	Ty = (int)floor((double)((player.y * ZOOM) + y + -wh) / (ZOOM)) % 100;

	if (Tx < 0)
		Tx += 100;
	if (Ty < 0)
		Ty += 100;

	if (CC.PlantMap.find(Ty) != CC.PlantMap.end() &&
		CC.PlantMap[Ty].find(Tx) != CC.PlantMap[Ty].end())
	{
		if (CC.PlantMap[Ty][Tx].m_type != 0
			&& CC.PlantMap[Ty][Tx].b_cut == 0
			&& CC.PlantMap[Ty][Tx].m_currentGrowth >= 99)
		{
			player.insertItemInv(new Wheat_Item());
			CC.PlantMap[Ty][Tx].b_cut = 1;
			CC.UpdateChunk();
		}
	}
}


// =================================================================== Wheat Seed Item 
Wheat_Seed_Item::Wheat_Seed_Item()
{
	m_id = 20;
	m_name = "Wheat Seeds";
	m_quanity = 1;
	m_classType = 's';
}

void Wheat_Seed_Item::doClick(int x, int y)
{
	int	ww = WINDOW_WIDTH / 2;
	int	wh = WINDOW_HEIGHT / 2;

	int	Cx, Cy, Tx, Ty;

	Cx = floor((double)((player.x * ZOOM) + x + -(WINDOW_WIDTH / 2)) / (ZOOM * 100));
	Cy = floor((double)((player.y * ZOOM) + y + -(WINDOW_HEIGHT / 2)) / (ZOOM * 100));

	Chunk& CC = ChunkMap[Cy][Cx];

	Tx = (int)floor((double)((player.x * ZOOM) + x + -ww) / (ZOOM)) % 100;
	Ty = (int)floor((double)((player.y * ZOOM) + y + -wh) / (ZOOM)) % 100;

	if (Tx < 0)
		Tx += 100;
	if (Ty < 0)
		Ty += 100;

	if (CC.PlantMap.find(Ty) != CC.PlantMap.end() &&
		CC.PlantMap[Ty].find(Tx) != CC.PlantMap[Ty].end())
	{
		if (CC.PlantMap[Ty][Tx].m_type == 0)
			CC.PlantMap[Ty][Tx] = Wheat();
		CC.UpdateChunk();
	}

}


// =================================================================== Wheat Seed Item 
Wheat_Item::Wheat_Item()
{
	m_id = 40;
	m_name = "Wheat";
	m_quanity = 1;
	m_classType = 'p';
}

void Wheat_Item::doClick(int x, int y)
{

}