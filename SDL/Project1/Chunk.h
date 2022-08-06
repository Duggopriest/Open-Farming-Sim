#ifndef CHUNK_H
# define CHUNK_H

#include <SDL.h>
#include <map>
#include "Plant.h"

typedef struct s_texture_array
{
	SDL_Texture* texture;
} Texture_Array;

class Chunk
{
	public:
		~Chunk();


		void	DrawChunk();
		void	GenChunk();
		void	UpdateChunk();

		void	Unload();

		unsigned char terrain[100][100];
		unsigned char airable[100][100];
		unsigned char fert[100][100];
		unsigned char hydro[100][100];
		unsigned char plowed[100][100];
		unsigned char buildings[100][100];

		// pointer of plants to draw


		bool edited;
		bool loaded;

		int x;
		int y;

		int px;
		int py;

		Texture_Array textures[100][100];

		std::map <int, std::map < int, Plant > > PlantMap;
};


#endif