#ifndef HEADER_HPP
# define HEADER_HPP

#include "include/SDL.h"
#include "include/SDL_ttf.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>
#include <time.h>
#include <chrono>
#include <thread>

#include "Player.h"
#include "Item.h"
#include "PerlinNoise.h"
#include "Chunk.h"
#include "Map.h"
#include "UI.h"
#include "msgpack.hpp"

using std::cout;
using std::endl;
using std::string;

extern int	Program_Running;
extern int	Chunks_Rendered;

extern int	Terrain_Seed;
extern int	Fert_Seed;
extern int	Moist_Seed;

extern Texture_Array Terrain_Base[255];
extern Texture_Array Building_Base[255];
extern Texture_Array Plant_Base[255];
extern Texture_Array Player_Base[255];
extern Texture_Array ITEM_BASE[255];

extern	Ui UI;
extern	Item* mouseItem;
extern	unsigned char	MENUID;

extern std::map <int, std::map < int, Chunk > > ChunkMap; // where the chunks are stored


extern Player player;
extern int MONEY;

// plant array

extern const int WINDOW_WIDTH, WINDOW_HEIGHT;

extern int ZOOM;

extern SDL_Event event;
extern SDL_Renderer* renderer;
extern SDL_Window* window;

extern bool EXIT;


// Global Functions
void	BuildGlobals();
void	SaveGame();
void	LoadGame();
Item*	getItem(unsigned char id);
void	exitGame(void);


#endif