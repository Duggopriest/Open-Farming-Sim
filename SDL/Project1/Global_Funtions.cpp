#include "Header.hpp"

int	Terrain_Seed;
int	Airable_Seed;

Texture_Array Terrain_Base[255];
Texture_Array Building_Base[255];
Texture_Array Plant_Base[255];
Texture_Array Player_Base[255];

Ui UI;

std::map <int, std::map < int, Chunk > > ChunkMap;

Player player;

const int WINDOW_WIDTH = 1920, WINDOW_HEIGHT = 1000;

SDL_Event event;
SDL_Renderer* renderer;
SDL_Window* window;

int ZOOM;

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

void	buildUi()
{
	UI.v_buttons.push_back(Button(0, 0, 5, 5));// = Button(0, 0, 100, 100);
}

void	buildInGameUi()
{
	UI.v_buttons.clear();
	UI.v_buttons.push_back(Button(0, 0, 100, 100));// = Button(0, 0, 100, 100);
}

void	getTextures()
{
	std::cout << "assigning Global Player Textures...\n"; // ==================================== Player Textures

	Player_Base[0].texture = NULL;

	Player_Base[1].texture = Load_Texture("textures/p.bmp");



	std::cout << "assigning Global Terrain Textures...\n"; // ==================================== Terrain Textures

	Terrain_Base[0].texture = NULL;

	Terrain_Base['g'].texture = Load_Texture("textures/g.bmp");
	Terrain_Base['r'].texture = Load_Texture("textures/r.bmp");
	Terrain_Base['w'].texture = Load_Texture("textures/w.bmp");
	Terrain_Base['t'].texture = Load_Texture("textures/t.bmp");

	

	std::cout << "assigning Global Terrain Textures...\n"; // ==================================== Terrain Textures

	Plant_Base[0].texture = Load_Texture("textures/plowed.bmp");
	Plant_Base[1].texture = Load_Texture("textures/wheat_1.bmp");
	Plant_Base[2].texture = Load_Texture("textures/wheat_2.bmp");
	Plant_Base[3].texture = Load_Texture("textures/wheat_3.bmp");
	Plant_Base[4].texture = Load_Texture("textures/wheat_4.bmp");


}

void	BuildGlobals()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	ZOOM = 50;

	Terrain_Seed = 6342;
	Airable_Seed = 4523;

	player.x = 1;
	player.y = 1;
	player.speed = 5;

	getTextures();
	cout << "Building UI\n";
	buildUi();
	cout << "Globals Loaded!\n";
}
