/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO

#include "../SDL/Project1/Header.hpp"


int	Program_Running;
int	Chunks_Rendered;
int	angle;
bool isSaving;
bool isLoading;

Item* mouseItem;

void	Draw_Grid()
{
	SDL_SetRenderDrawColor(renderer, 100, 0, 100, 0);
	for (float y = 0; y < 1000; y++)
	{
		if (((int)(y + player.y) % 50) == 0)
			SDL_RenderDrawLine(renderer, 0, y, 1920, y);
	}
	SDL_SetRenderDrawColor(renderer, 100, 100, 0, 0);
	for (float x = 0; x < 1920; x++)
	{
		if (((int)(x + player.x) % 50) == 0)
			SDL_RenderDrawLine(renderer, x, 0, x, 1920);
	}
}

void Display_playerPos() 
{
	TTF_Init();
	std::string Message;
	
	TTF_Font* font = TTF_OpenFont("font.ttf", 20);
	if (!font)
		std::cout << "Couldn't find/init open ttf font." << std::endl;
	SDL_Color TextColor = { 255, 255, 255, 255 };
	
	Message = "x: " + std::to_string(floor((double)player.x / 25000)) + "    |     " + std::to_string(player.x);

	SDL_Surface* TextSurface = TTF_RenderText_Solid(font, &Message.at(0), TextColor);
	SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
	SDL_Rect TextRect = { 0, 0, TextSurface->w, TextSurface->h };
	SDL_RenderCopy(renderer, TextTexture, NULL, &TextRect);

	SDL_FreeSurface(TextSurface);
	SDL_DestroyTexture(TextTexture);

	Message = "y: " + std::to_string(floor((double)player.y / 25000)) + "    |     " + std::to_string(player.y);

	TextSurface = TTF_RenderText_Solid(font, &Message.at(0), TextColor);
	TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
	TextRect = { 0, 20, TextSurface->w, TextSurface->h };
	
	SDL_RenderCopy(renderer, TextTexture, NULL, &TextRect);

	SDL_FreeSurface(TextSurface);
	SDL_DestroyTexture(TextTexture);
	TTF_CloseFont(font);

	TTF_Quit();
}

void Display_Frame_Time(int &delta)
{
	std::string Message;

	TTF_Font* font = TTF_OpenFont("font.ttf", 20);

	if (!font)
		std::cout << "Couldn't find/init open ttf font." << std::endl;

	SDL_Color TextColor = { 255, 255, 255, 255 };

	Message = "frame time: " + std::to_string(delta);


	SDL_Surface* TextSurface = TTF_RenderText_Solid(font, Message.c_str(), TextColor);
	SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);

	SDL_Rect TextRect = { 0, 80, TextSurface->w, TextSurface->h };


	SDL_RenderCopy(renderer, TextTexture, NULL, &TextRect);

	SDL_FreeSurface(TextSurface);
	SDL_DestroyTexture(TextTexture);
	TTF_CloseFont(font);
}

void render_frame()
{
	
}

void	Th_DrawChunks(Map *map)
{
	map->RenderChunks();
}

bool	doKeyboard(double Tdelta)
{
	static bool tabLock = true;
	static bool altLock = true;
	const Uint8* state;
	if (0 > Tdelta > 10)
		Tdelta = .001;

	state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_W])
	{
		player.angle = 0;
		player.y -= Tdelta;
	}
	if (state[SDL_SCANCODE_S])
	{
		player.angle = 180;
		player.y += Tdelta;
	}
	if (state[SDL_SCANCODE_A])
	{
		player.angle = 270;
		player.x -= Tdelta;
	}
	if (state[SDL_SCANCODE_D])
	{
		player.angle = 90;
		player.x += Tdelta;
	}
	if (state[SDL_SCANCODE_TAB]) // ============== tab
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_TAB)
					tabLock = false;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_TAB)
					tabLock = true;
			break;
		}
		if (tabLock)
		{
			UI.displayInv = !UI.displayInv;
			tabLock = false;
		}
	}
	if (state[SDL_SCANCODE_LALT])
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_LALT)
				altLock = false;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_LALT)
				altLock = true;
			break;
		}
		if (altLock)
		{
			UI.displaySelected = !UI.displaySelected;
			altLock = false;
		}
	}
	for (int i = 0; i < 10; i++) // ============== numbers
	{
		if (state[30 + i])
		{
			player.m_TBSelected = i;
		}
	}
	if (state[SDL_SCANCODE_ESCAPE]) // ============== escape
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				tabLock = false;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				tabLock = true;
			break;
		}
		if (tabLock)
		{
			if (MENUID == 0)
				MENUID = 1;
			else
			{
				MENUID = 0;
				UI.clearUi();
			}
			tabLock = false;
		}
	}

	return (0);
}

void	doMouse(SDL_Event& event)
{
	bool mouseLock = false;
	if (event.type == SDL_MOUSEWHEEL)
	{
		if (event.wheel.y > 0) // scroll up
		{
			// Put code for handling "scroll up" here!

			if (ZOOM < 100)
				ZOOM += event.wheel.y;
		}
		else if (event.wheel.y < 0) // scroll down
		{
			// Put code for handling "scroll down" here!

			if (ZOOM > 10)
				ZOOM += event.wheel.y;
		}
		/*
		if (event.wheel.x > 0) // scroll right
		{
			// ...
		}
		else if (event.wheel.x < 0) // scroll left
		{
			// ...
		}
		*/
	}

	int	x, y, newitemnum;
	static int itemnum;
	static bool	fromInv;
	Uint32 MouseState = SDL_GetMouseState(&x, &y);

	int	ww = WINDOW_WIDTH / 2;
	int	wh = WINDOW_HEIGHT / 2;

	if (UI.displaySelected || (event.type == SDL_MOUSEBUTTONDOWN && !mouseLock))
		UI.getMouseCords();
	
	if (event.type == SDL_MOUSEBUTTONDOWN && !mouseLock)
	{
		// ... handle mouse clicks ...
		SDL_MouseButtonEvent mouseEvent;

		// ====================================================================== LEFT
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			if (player.a_invontory[player.m_TBSelected + 100] && !UI.displayInv)
				player.a_invontory[player.m_TBSelected + 100]->doClick();
			// =============================== inv check
			else if (UI.displayInv && !mouseItem)
			{
				itemnum = (x - (ww - 250)) / 50 + ((y - (WINDOW_HEIGHT - 550)) / 50) * 10;
				if (itemnum > -1 && itemnum < 110)
				{
					mouseItem = player.a_invontory[itemnum];
				}
			}
		}
		// ====================================================================== MIDDLE
		else if (event.button.button == SDL_BUTTON_MIDDLE)
		{
			cout << "X: " << x << endl;
			cout << "Y: " << y << endl;
			cout << "player X: " << player.x << endl;
			cout << "player Y: " << player.y << endl;
			cout << "ZOOM: " << ZOOM << endl;
			cout << "ZOOM / 50: " << (double)ZOOM / 50 << endl;
		}
		// ====================================================================== RIGHT
		else if (event.button.button == SDL_BUTTON_RIGHT)
		{
		}
		//ChunkMap[Cy][Cx].textures[Ty][Tx].texture = Terrain_Base['r'].texture;
	}
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		if (UI.checkButtonsClick(x, y))
			return ;
		else if (mouseItem
			&& x < ww + 250
			&& y < WINDOW_HEIGHT)
		{
			newitemnum = (x - (ww - 250)) / 50 + ((y - (WINDOW_HEIGHT - 550)) / 50) * 10;
			if (newitemnum >= 0 && newitemnum < 110)
			{
				if (!player.a_invontory[newitemnum])
				{
					player.a_invontory[itemnum] = NULL;
					player.a_invontory[newitemnum] = mouseItem;
					cout << "putting " << mouseItem->m_name << " into inv\n";
				}
			}
		}
		mouseItem = NULL;
		mouseLock = false;
	}
}
/*
#include "../SDL/Project1/shader.h"

int		glGetUniformLocation(int program, const char* name);
void	glUniform1f(int location, float v0);
void	glUniform2f(int location, float v0, float v1);
*/
int main(int argc, char* args[]) {
	Program_Running = 1;
	isSaving = false;
	isLoading = false;
	TTF_Init();

	BuildGlobals();

	Map map;

	const Uint8* state; // for keyboard

	TTF_Init();

	time_t seconds = time(NULL);
	time_t fpsTimer = time(NULL);
	time_t plantUpdateTimer = time(NULL);
	bool plantUT = false;
	bool plantUTR = false;
	int	frame = 0;
	int	fps = 300;
	
	Chunks_Rendered = 1;

	std::thread PlantThread;
	std::thread TerrainThread;

	std::cout << "Stating\n";
	while (EXIT) 
	{

		if (isSaving)
		{
			isSaving = false;
			SaveGame();
		}
		if (isLoading)
		{
			isLoading = false;
			LoadGame();
		}
		
		// map.RenderChunks();

		//Draw_Grid();

		//threads.doJob(std::bind(Th_DrawChunks, map));
		
		//Display_playerPos();


		TerrainThread = std::thread(&Map::RenderChunks, map);  // ================= Renders Chunks

		// how often plants get updated
		plantUT = false;
		if (seconds == plantUpdateTimer + 1)
		{
			if (plantUTR)
				PlantThread.join(); PlantThread.~thread();		// waits for map.updatePlants(); to be done
			plantUT = true;
			plantUTR = true;
			plantUpdateTimer = time(NULL);
		}
		if (plantUT)
			PlantThread = std::thread(&Map::updatePlants, map, plantUT); // ====== Updates All Plants

		doMouse(event);
		doKeyboard(player.speed / fps);

		


		seconds = time(NULL);
		if (seconds == fpsTimer + 1)
		{
			fps = frame;
			frame = 0;
			fpsTimer = time(NULL);
		}
		else
			frame++;
		

		//map.RenderChunks();
		//if (plantUT == true)
		
		TerrainThread.join(); TerrainThread.~thread();		// waits for map.RenderChunks(); to be done


		player.drawPlayer();
		UI.drawUi();

		Display_Frame_Time(fps);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
    }

	if (plantUTR)
		PlantThread.join(); PlantThread.~thread();

	Program_Running = 0;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
