#include "Header.hpp"

int	Terrain_Seed;
int	Airable_Seed;

Texture_Array Terrain_Base[255];
Texture_Array Building_Base[255];
Texture_Array Plant_Base[255];

std::map <int, std::map < int, Chunk > > Chunk_Map;

Player player;

SDL_Event event;
SDL_Renderer* renderer;
SDL_Window* window;

SDL_Texture* Load_Texture(const char *str)
{
	SDL_Surface* S = SDL_LoadBMP(str);
	if (S == NULL)
	{
		std::cout << "		!!!!!!!!! Failed to load !!!!!!!!!	" << str << std::endl;
		return (NULL);
	}
	SDL_Texture *temp = SDL_CreateTextureFromSurface(renderer, S);
	SDL_FreeSurface(S);
	std::cout << "		successfuly loaded " << str << std::endl;
	return(temp);
}

void	assignCopyTiles()
{
	std::cout << "assigning Global Terrain Textures...\n";

	Terrain_Base[0].texture = NULL;

	Terrain_Base['g'].texture = Load_Texture("textures/g.bmp");
	Terrain_Base['r'].texture = Load_Texture("textures/r.bmp");
	Terrain_Base['w'].texture = Load_Texture("textures/w.bmp");
	Terrain_Base['t'].texture = Load_Texture("textures/t.bmp");
}

void	BuildGlobals()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(1920, 1000, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);


	Terrain_Seed = 6342;
	Airable_Seed = 4523;

	player.x = 1;
	player.y = 1;


	assignCopyTiles();
}
