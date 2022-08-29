#ifndef CHUNK_H
# define CHUNK_H

#include <SDL.h>
#include <map>
#include <array>
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
		void	doPlantCal();

		void	Unload();

		int id;



		unsigned char terrain[100][100];
		unsigned char airable[100][100];
		unsigned char fert[100][100];
		std::array< std::array<unsigned char, 100>, 100> sa_fert;
		unsigned char hydro[100][100];
		std::array< std::array<unsigned char, 100>, 100> sa_hydro;
		unsigned char buildings[100][100];
		std::array< std::array<unsigned char, 100>, 100> sa_buildings;

		// pointer of plants to draw


		bool edited;
		bool loaded;

		int x;
		int y;

		int px;
		int py;

		Texture_Array textures[100][100];

		std::map <int, std::map < int, Plant > > PlantMap;

		template<class T>
		void pack(T& pack) {
			pack(id, x, y, px, py, edited, loaded,
				sa_fert,
				sa_hydro,
				sa_buildings,
				PlantMap);
		}
};


#endif