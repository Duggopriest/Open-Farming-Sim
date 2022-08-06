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
	dstrect.h = ZOOM + 1;
	dstrect.w = ZOOM + 1;

	int	zoomMod = ZOOM - 50;

	//int	cenx = (((WINDOW_WIDTH) / 2) * zoomMod + px) - player.x);
	//int	ceny = (((WINDOW_HEIGHT) / 2) * zoomMod + py) - player.y);

	int	ww = WINDOW_WIDTH / 2;
	int	wh = WINDOW_HEIGHT / 2;

	double	cenx = (ww - player.x) - ww;
	double	ceny = (wh - player.y) - wh;

	double modX = ww + px + (x * zoomMod * 100);
	double modY = wh + py + (y * zoomMod * 100);

	for (int oy = 0; oy < 100; oy++)
	{
		for (int ox = 0; ox < 100; ox++)
		{
			//dstrect.x = ((ox + ZOOM) * ZOOM) + cenx;
			//dstrect.y = ((oy + ZOOM) * ZOOM) + ceny;

			//dstrect.x = ox * ZOOM + cenx;
			//dstrect.y = oy * ZOOM + ceny;

			dstrect.x = (ox + cenx) * ZOOM + modX;
			dstrect.y = (oy + ceny) * ZOOM + modY;

			//dstrect.x = ((ox + cenx) - (WINDOW_WIDTH / 2)) * ZOOM + (WINDOW_WIDTH / 2);
			//dstrect.y = ((oy + ceny) - (WINDOW_HEIGHT / 2)) * ZOOM + (WINDOW_HEIGHT / 2);

			SDL_RenderCopy(renderer, textures[oy][ox].texture, NULL, &dstrect);
			//SDL_RenderCopy(renderer, Terrain_Base[terrain[oy][ox]].texture, NULL, &dstrect); // no need for Texture_Array textures[200][200];
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

			if (temp >= 80)
				terrain[oy][ox] = 't';
			else if (temp < 80 && temp >= 47)
				terrain[oy][ox] = 'g';
			else if (temp < 47 && temp >= 45)
				terrain[oy][ox] = 'r';
			else if (temp < 45 && temp >= 15)
				terrain[oy][ox] = 'g';
			else if (temp < 15)
				terrain[oy][ox] = 'w';

			textures[oy][ox].texture = Terrain_Base[terrain[oy][ox]].texture;
		}
	}

	PerlinNoise Airable_Noise(Airable_Seed);
	//------------------------------------------- AIRABLE ---------------------------------------
	for (int oy = 0; oy < 100; oy++)
	{
		for (int ox = 0; ox < 100; ox++)
		{
			temp = Airable_Noise.noise(ox / 10, oy / 10, .5) * 100;

			airable[oy][ox] = (unsigned char)temp;
		}
	}

	loaded = true;
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
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
				textures[oy][ox].texture = Plant_Base[PlantMap[oy][ox].m_type].texture;
			}
		}
	}
}

void	Chunk::Unload()
{
	
}

