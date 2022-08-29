#include "Header.hpp"
#include <fstream>


int	Terrain_Seed;
int	Airable_Seed;

Texture_Array Terrain_Base[255];
Texture_Array Building_Base[255];
Texture_Array Plant_Base[255];
Texture_Array Player_Base[255];
Texture_Array ITEM_BASE[255];

Ui UI;
unsigned char	MENUID;

std::map <int, std::map < int, Chunk > > ChunkMap;

Player player;


const int WINDOW_WIDTH = 1920, WINDOW_HEIGHT = 1000;

SDL_Event event;
SDL_Renderer* renderer;
SDL_Window* window;

bool	EXIT;

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

void	exitGame(void)
{
	EXIT = 0;
}


void	buildUi()
{
	//UI.v_buttons.push_back(Button(0, 0, 5, 5));
	UI.menus.resize(2);
	MENUID = 0;
	t_menus *cmenu;

	// =================================== Esc menu
	cmenu = &UI.menus[1];
	cmenu->id = 1;
	cmenu->name = "menu";
	cmenu->blocks.push_back(SDL_Rect(WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 - 120, 250, 500));
	cmenu->colours.push_back(SDL_Color(40, 30, 20, 0));

	cmenu->v_buttons.push_back(Button(WINDOW_WIDTH / 2 - 110, WINDOW_HEIGHT / 2 - 100, 220, 95, SaveGame, SDL_Color(0, 255, 0, 0), "Save"));

	cmenu->v_buttons.push_back(Button(WINDOW_WIDTH / 2 - 110, WINDOW_HEIGHT / 2, 220, 95, LoadGame, SDL_Color(255, 0, 0, 0), "Load"));

	cmenu->v_buttons.push_back(Button(WINDOW_WIDTH / 2 - 110, WINDOW_HEIGHT / 2 + 100, 220, 95, exitGame, SDL_Color(100, 100, 100, 0), "Exit"));
}

void	buildInGameUi()
{
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

	

	std::cout << "assigning Global Plant Textures...\n"; // ==================================== Terrain Textures

	Plant_Base[0].texture = Load_Texture("textures/plowed.bmp"); 
	Plant_Base[1].texture = Load_Texture("textures/wheat_1.bmp");
	Plant_Base[2].texture = Load_Texture("textures/wheat_2.bmp");
	Plant_Base[3].texture = Load_Texture("textures/wheat_3.bmp");
	Plant_Base[4].texture = Load_Texture("textures/wheat_4.bmp");
	Plant_Base[5].texture = Load_Texture("textures/cut_wheat.bmp");



	std::cout << "assigning Global Item Textures...\n"; // ==================================== Terrain Textures

	ITEM_BASE[0].texture = NULL;
	ITEM_BASE[1].texture = Load_Texture("textures/plow_item.bmp");
	ITEM_BASE[2].texture = Load_Texture("textures/scythe_item.bmp");
	ITEM_BASE[20].texture = Load_Texture("textures/wheat_seed_item.bmp");
	ITEM_BASE[40].texture = Load_Texture("textures/wheat_item.bmp");


}

// ================================= Build Global vars
void	BuildGlobals() 
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);



	ZOOM = 50;
	EXIT = 1;

	Terrain_Seed = 6342;
	Airable_Seed = 4523;

	player.x = 1;
	player.y = 1;
	player.speed = 5;
	player.insertItemInv(new Plow_Item());
	player.insertItemInv(new Wheat_Seed_Item());
	player.insertItemInv(new Scythe_Item());

	getTextures();
	cout << "Building UI\n";
	buildUi();
	cout << "Globals Loaded!\n";
}

class SaveClass
{
	public:
		template<class T>
		void pack(T& pack) {
			pack(player, Terrain_Seed, Airable_Seed, Chunks_Rendered, ChunkMap);
		}
};

void	packPlayer()
{
	for (int i = 0; i < 110; i++)
	{
		if (player.a_invontory[i])
			player.sa_invontory[i] = player.a_invontory[i]->m_id;
		else
			player.sa_invontory[i] = 0;
	}
}

Item* getItem(unsigned char id)
{
	switch (id)
	{
	default: new Item();
		case 0: return NULL;
		case 1: return new Plow_Item();
		case 2: return new Scythe_Item();
		case 20: return new Wheat_Seed_Item();
		case 40: return new Wheat_Item();
	};
}

void	unpackPlayer()
{
	for (int i = 0; i < 110; i++)
		player.a_invontory[i] = getItem(player.sa_invontory[i]);
}

void	packChunk(Chunk& chunk)
{
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 100; x++)
		{
			chunk.sa_fert[y][x] = chunk.fert[y][x];
			chunk.sa_hydro[y][x] = chunk.hydro[y][x];
			chunk.sa_buildings[y][x] = chunk.buildings[y][x];
		}
	}
}

void	unpackChunk(Chunk& chunk)
{
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 100; x++)
		{
			chunk.fert[y][x] = chunk.sa_fert[y][x];
			chunk.hydro[y][x] = chunk.sa_hydro[y][x];
			chunk.buildings[y][x] = chunk.sa_buildings[y][x];
		}
	}
}

void	SaveGame()
{
	SaveClass sc;

	cout << "SAVING\n";
	packPlayer();

	ChunkMap[-1][0].id = 420;

	cout << ChunkMap[-1][0].id << endl;

	std::map <int, std::map < int, Chunk > >::iterator itr;
	std::map < int, Chunk >::iterator ptr;

	for (itr = ChunkMap.begin(); itr != ChunkMap.end(); itr++)
	{
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
		{
			packChunk(ptr->second);
		}
	}

	std::vector<uint8_t> data = msgpack::pack(sc); // Pack object

	std::ofstream out("test", std::ios::out | std::ios::binary);
	out.write((char*)&data[0], data.size());
	out.close();

	cout << "done\n";
}

typedef unsigned char BYTE;
std::vector<BYTE> readFile(const char* filename)
{
	// open the file:
	std::streampos fileSize;
	std::ifstream file(filename, std::ios::binary);

	// get its size:
	file.seekg(0, std::ios::end);
	fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	// read the data:
	std::vector<BYTE> fileData(fileSize);
	file.read((char*)&fileData[0], fileSize);
	return fileData;
}

void	LoadGame()
{
	cout << "LOADDING\n";
	std::vector<BYTE> data = readFile("test");

	cout << "unpacking" << endl;
	SaveClass sc = msgpack::unpack<SaveClass>(data);

	unpackPlayer();


	cout << "updating chunks" << endl;
	// updates all chunks
	std::map <int, std::map < int, Chunk > >::iterator itr;
	std::map < int, Chunk >::iterator ptr;

	for (itr = ChunkMap.begin(); itr != ChunkMap.end(); itr++)
	{
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
		{
			unpackChunk(ptr->second);
			ptr->second.GenChunk();
			ptr->second.UpdateChunk();
		}
	}
	cout << "done\n";
}

/*
void CreateText(const char* Message)
{
	
	TTF_Font* font = TTF_OpenFont(FONT_NAME, FONT_SIZE);
	if (!font)
		std::cout << "Couldn't find/init open ttf font." << std::endl;
	SDL_Color TextColor = { 245, 245, 220, 0 };
	SDL_Surface* TextSurface = TTF_RenderText_Solid(font, Message, TextColor);
	SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
	SDL_Rect TextRect = { 0, 0, TextSurface->w, TextSurface->h };
	SDL_FreeSurface(TextSurface);
	SDL_RenderCopy(renderer, TextTexture, NULL, &TextRect);
}
*/