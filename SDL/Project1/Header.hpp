#ifndef HEADER_HPP
# define HEADER_HPP

#include <SDL.h>
#include <SDL_ttf.h>
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
#include "PerlinNoise.h"
#include "Chunk.h"
#include "Map.h"

using std::cout;
using std::endl;

extern int	Program_Running;

extern int	Chunks_Rendered;

extern int	Terrain_Seed;
extern int	Airable_Seed;

extern Texture_Array Terrain_Base[255];
extern Texture_Array Building_Base[255];
extern Texture_Array Plant_Base[255];


extern std::map <int, std::map < int, Chunk > > Chunk_Map; // where the chunks are stored


extern Player player;


static const char* FONT_NAME = "font.ttf";
static const int FONT_SIZE = 20;
static const int WINDOW_WIDTH = 1280, WINDOW_HEIGHT = 720;


extern SDL_Event event;
extern SDL_Renderer* renderer;
extern SDL_Window* window;


// Global Functions
void	BuildGlobals();


#endif