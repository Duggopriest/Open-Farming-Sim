#include "Header.hpp"
#include <fstream>


int	Terrain_Seed;
int	Fert_Seed;
int	Moist_Seed;

Texture_Array Terrain_Base[255];
Texture_Array Building_Base[255];
Texture_Array Plant_Base[255];
Texture_Array Player_Base[255];
Texture_Array ITEM_BASE[255];

Ui UI;
unsigned char	MENUID;

std::map <int, std::map < int, Chunk > > ChunkMap;

Player player;
int MONEY;

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

void	getGrassTextures()
{
	Terrain_Base['g'].texture = Load_Texture("textures/g1.bmp");
	Terrain_Base['h'].texture = Load_Texture("textures/g2.bmp");
	Terrain_Base['i'].texture = Load_Texture("textures/g3.bmp");
	Terrain_Base['j'].texture = Load_Texture("textures/g4.bmp");
	Terrain_Base['k'].texture = Load_Texture("textures/g5.bmp");
	Terrain_Base['l'].texture = Load_Texture("textures/g6.bmp");
	Terrain_Base['m'].texture = Load_Texture("textures/g7.bmp");
	Terrain_Base['n'].texture = Load_Texture("textures/g8.bmp");
	Terrain_Base['o'].texture = Load_Texture("textures/g9.bmp");
}

void	getTextures()
{
	std::cout << "assigning Global Player Textures...\n"; // ==================================== Player Textures

	Player_Base[0].texture = NULL;

	Player_Base[1].texture = Load_Texture("textures/p.bmp");



	std::cout << "assigning Global Terrain Textures...\n"; // ==================================== Terrain Textures

	Terrain_Base[0].texture = NULL;

	getGrassTextures();
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
	window = SDL_CreateWindow("Open Farm Sim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0 | SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	//SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	

	ZOOM = 50;
	EXIT = 1;

	Terrain_Seed = 6342;
	Fert_Seed = 2577;
	Moist_Seed = rand();

	player.x = 1;
	player.y = 1;
	player.speed = 5;
	player.insertItemInv(new Plow_Item());
	player.insertItemInv(new Wheat_Seed_Item());
	player.insertItemInv(new Scythe_Item());

	MONEY = 0;

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
			pack(player, Terrain_Seed, Fert_Seed, Chunks_Rendered, ChunkMap);
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
			chunk.sa_moist[y][x] = chunk.moist[y][x];
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
			chunk.moist[y][x] = chunk.sa_moist[y][x];
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
std::vector<BYTE> readFile(const char* filename, bool *fail)
{
	// open the file:
	std::streampos fileSize;
	std::ifstream file(filename, std::ios::binary);

	if (file.fail())
	{
		*fail = true;
		std::vector<BYTE> fileData(fileSize);
		return fileData;
	}

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
	bool fail;
	cout << "LOADDING\n";
	std::vector<BYTE> data = readFile("test", &fail);

	if (fail)
	{
		cout << "!!!FAILED TO LOAD!!!" << endl;
		//return;
	}

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
