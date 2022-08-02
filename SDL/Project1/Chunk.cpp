#include "Chunk.h"
#include "PerlinNoise.h"
#include "Header.hpp"


void	Chunk::DrawChunk()
{
	if (!loaded)
		GenChunk();
	SDL_Rect dstrect;
	dstrect.h = 51;
	dstrect.w = 51;

	for (int oy = 0; oy < 100; oy++)
	{
		for (int ox = 0; ox < 100; ox++)
		{
			dstrect.x = (ox * 50 - player.x) + px;
			dstrect.y = (oy * 50 - player.y) + py;
			SDL_RenderCopy(renderer, textures[oy][ox].texture, NULL, &dstrect);
			// SDL_RenderCopy(renderer, Terrain_Base[terrain[oy][ox]].texture, NULL, &dstrect); // no need for Texture_Array textures[200][200];
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

void	Chunk::Unload()
{
	
}

Chunk::~Chunk()
{
}