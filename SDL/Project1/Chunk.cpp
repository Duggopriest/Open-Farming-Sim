#include "Chunk.h"
#include "PerlinNoise.h"
#include "Header.hpp"

Chunk::~Chunk()
{
}

void	Chunk::DrawChunk()
{
	if (!loaded)
		GenChunk();
	SDL_Rect dstrect;
	dstrect.h = ZOOM;
	dstrect.w = ZOOM;

	int	zoomMod = ZOOM - 50;

	int	ww = WINDOW_WIDTH / 2;
	int	wh = WINDOW_HEIGHT / 2;

	double	cenx = (ww - player.x) - ww;
	double	ceny = (wh - player.y) - wh;

	double modX = ww + px + (x * zoomMod * 100);
	double modY = wh + py + (y * zoomMod * 100);
	
	int	colorVal;

	for (int oy = 0; oy < 100; oy++)
	{
		for (int ox = 0; ox < 100; ox++)
		{
			dstrect.x = (ox + cenx) * ZOOM + modX;
			dstrect.y = (oy + ceny) * ZOOM + modY;

			colorVal = moist[oy][ox] * 3.5;
			colorVal = (colorVal > 255 ? 255 : colorVal);

			SDL_SetTextureColorMod(textures[oy][ox].texture, colorVal, colorVal, colorVal);
			SDL_RenderCopy(renderer, textures[oy][ox].texture, NULL, &dstrect);
			
		}
	}
}

void	Chunk::GenChunk()
{
	double temp;
	PerlinNoise Terrain_Noise(Terrain_Seed);

	cout << "Generating Chunk num " << Chunks_Rendered++ << endl;

	//------------------------------------------- TERRAIN ---------------------------------------
	for (int oy = 0; oy < 100; oy++)
	{
		for (int ox = 0; ox < 100; ox++)
		{
			temp = Terrain_Noise.noise((double)(ox + x * 100) / 20, (double)(oy + y * 100) / 20, .5) * 100;
			moist[oy][ox] = (-(unsigned char)temp + 100) * 0.25;

			if (temp >= 80)
				terrain[oy][ox] = 't';
			else if (temp < 80 && temp >= 47)
				terrain[oy][ox] = 'g';
			else if (temp < 47 && temp >= 45)
				terrain[oy][ox] = 'r';
			else if (temp < 45 && temp >= 15)
				terrain[oy][ox] = 'g';
			else if (temp < 15)
			{
				moist[oy][ox] = 100;
				terrain[oy][ox] = 'w';
			}
			
			textures[oy][ox].texture = Terrain_Base[terrain[oy][ox]].texture;
		}
	}

	PerlinNoise Fert_Noise(Fert_Seed);
	//------------------------------------------- Fertlizer ---------------------------------------
	for (int oy = 0; oy < 100; oy++)
	{
		for (int ox = 0; ox < 100; ox++)
		{
			temp = Fert_Noise.noise((double)(ox + x * 100) / 20, (double)(oy + y * 100) / 20, .5) * 50;

			fert[oy][ox] = (unsigned char)temp;
		}
	}

	PerlinNoise Moist_Noise(Moist_Seed);
	//------------------------------------------- Moisture ---------------------------------------
	for (int oy = 0; oy < 100; oy++)
	{
		for (int ox = 0; ox < 100; ox++)
		{
			temp = Moist_Noise.noise((double)(ox + x * 100) / 20, (double)(oy + y * 100) / 20, .5) * 75;

			moist[oy][ox] += (moist[oy][ox] + temp > 100 ? 100 : moist[oy][ox] + (unsigned char)temp);
		}
	}

	loaded = true;
	//std::cout << "x: " << x << std::endl;
	//std::cout << "y: " << y << std::endl;
}

void	Chunk::UpdateChunk()
{
	//int	mapSize = a_Plants.size();
	//std::map <int, Plant>::iterator it;

	for (int oy = 0; oy < 100; oy++)
	{
		for (int ox = 0; ox < 100; ox++)
		{
			if (PlantMap.find(oy) != PlantMap.end() &&
				PlantMap[oy].find(ox) != PlantMap[oy].end())
			{
				if (PlantMap[oy][ox].m_type != 0)
					textures[oy][ox].texture = Plant_Base[PlantMap[oy][ox].m_type + (unsigned char)(PlantMap[oy][ox].m_currentGrowth * 0.04) + PlantMap[oy][ox].b_cut].texture;
				else
					textures[oy][ox].texture = Plant_Base[PlantMap[oy][ox].m_type].texture;
			}
		}
	}
}

void	Chunk::doPlantCal()
{
	int	x;
	int	y;

	Plant* temp;

	std::map <int, std::map < int, Plant > >::iterator	itr;
	std::map < int, Plant >::iterator					ptr;

	for (itr = PlantMap.begin(); itr != PlantMap.end(); itr++)
	{
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
		{
			if (ptr->second.m_currentGrowth < 99)
			{
				ptr->second.m_currentGrowth += 5;
			}
			if (ptr->second.m_currentGrowth > 99)
				ptr->second.m_currentGrowth = 99;
		}
	}
}

void	Chunk::Unload()
{
	
}

