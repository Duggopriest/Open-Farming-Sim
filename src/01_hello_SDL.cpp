/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO

#include "../SDL/Project1/Header.hpp"


int	Program_Running;
int	Chunks_Rendered;

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

void CreateText(const char* Message) 
{
	TTF_Init();
	TTF_Font* font = TTF_OpenFont(FONT_NAME, FONT_SIZE);
	if (!font)
		std::cout << "Couldn't find/init open ttf font." << std::endl;
	SDL_Color TextColor = { 255, 255, 255, 255 };
	SDL_Surface* TextSurface = TTF_RenderText_Solid(font, Message, TextColor);;
	SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);;
	SDL_Rect TextRect = { 0, 0, TextSurface->w, TextSurface->h };
	SDL_FreeSurface(TextSurface);
	SDL_RenderCopy(renderer, TextTexture, NULL, &TextRect);
	TTF_Quit();
}

void Display_playerPos() 
{
	TTF_Init();
	std::string Message;
	
	TTF_Font* font = TTF_OpenFont(FONT_NAME, FONT_SIZE);
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
	TTF_Init();
	std::string Message;

	TTF_Font* font = TTF_OpenFont(FONT_NAME, FONT_SIZE);

	if (!font)
		std::cout << "Couldn't find/init open ttf font." << std::endl;

	SDL_Color TextColor = { 255, 255, 255, 255 };

	Message = "frame time: " + std::to_string(delta);


	SDL_Surface* TextSurface = TTF_RenderText_Solid(font, &Message.at(0), TextColor);
	SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);

	SDL_Rect TextRect = { 0, 80, TextSurface->w, TextSurface->h };


	SDL_RenderCopy(renderer, TextTexture, NULL, &TextRect);

	SDL_FreeSurface(TextSurface);
	SDL_DestroyTexture(TextTexture);
	TTF_CloseFont(font);


	TTF_Quit();
}

void render_frame()
{
	
}

void	Th_DrawChunks(Map *map)
{
	map->RenderChunks();
}

bool	doKeyboard()
{
	const Uint8* state;

	state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_W])
		player.y -= 1;
	if (state[SDL_SCANCODE_S])
		player.y += 1;
	if (state[SDL_SCANCODE_A])
		player.x -= 1;
	if (state[SDL_SCANCODE_D])
		player.x += 1;
	if (state[SDL_SCANCODE_ESCAPE])
		return (1);
	return (0);
}

int main(int argc, char* args[]) {
	
	Program_Running = 1;

	BuildGlobals();

	Map map;

	const Uint8* state; // for keyboard

	TTF_Init();

	time_t seconds = time(NULL);
	time_t next = time(NULL);
	int	frame = 0;
	int	fps = 0;
	

	Chunks_Rendered = 1;

	std::cout << "Stating\n";
	while (1) 
	{

		// map.RenderChunks();

		//Draw_Grid();

		//threads.doJob(std::bind(Th_DrawChunks, map));
		
		//Display_playerPos();


		std::thread TerrainThread(&Map::RenderChunks, map);
		
       
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;

		if (doKeyboard())
		{
			TerrainThread.join(); TerrainThread.~thread();
			break;
		}

		


		seconds = time(NULL);
		if (seconds == next + 1)
		{
			fps = frame;
			frame = 0;
			next = time(NULL);
		}
		else
			frame++;
		

		//map.RenderChunks();




		TerrainThread.join(); TerrainThread.~thread();
		Display_Frame_Time(fps);
		SDL_RenderPresent(renderer);
    }
	Program_Running = 0;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
