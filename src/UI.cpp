#include "UI.h"
#include "Header.hpp"
#include <iostream>

Button::Button() : m_x(0), m_y(0), m_sizeX(0), m_sizeY(0)
{
	funptr = NULL;
}

Button::~Button()
{
	//SDL_DestroyTexture(TextTexture);
	
}

Button::Button(int x, int y, int sizeX, int sizeY, void (*fun)(void), SDL_Color colour, std::string name) :
	m_x(x), m_y(y), m_sizeX(sizeX), m_sizeY(sizeY), color(colour), name(name)
{
	this->funptr = fun;

	// ================= Assign Text texture
	TTF_Font* font = TTF_OpenFont("font.ttf", 40);
	if (!font)
		std::cout << "Couldn't find/init open ttf font." << std::endl;

	SDL_Color TextColor = { 200, 173, 127, 0 };
	SDL_Surface* TextSurface = TTF_RenderText_Solid(font, name.c_str(), TextColor);
	TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
	TextRect = { x + (sizeX / 2) - TextSurface->w / 2, y + (sizeY / 2) - TextSurface->h / 2, TextSurface->w, TextSurface->h };
}

void	Button::onClick()
{
	funptr();
}

bool	Button::hasClicked(int x, int y)
{
	if (x > m_x && x < m_x + m_sizeX &&
		y > m_y && y < m_y + m_sizeY)
	{
		this->onClick();
		return (true);
	}
	return (false);
}

void	Button::drawButton()
{
	SDL_Rect rect = { m_x, m_y, m_sizeX, m_sizeY };
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);

	SDL_RenderCopy(renderer, TextTexture, NULL, &TextRect);
}

// ====================================================================	UI

Ui::Ui()
{
	displayInv = false;
	displaySelected = false;
	CC = NULL;
	x = 0;
	y = 0;
	Cx = 0;
	Cy = 0;
	Tx = 0;
	Ty = 0;
}

Ui::~Ui()
{
}

void	Ui::getMouseCords()
{
	int	ww = WINDOW_WIDTH / 2;
	int	wh = WINDOW_HEIGHT / 2;

	SDL_GetMouseState(&x, &y);

	Cx = floor((double)((player.x * ZOOM) + x + -(ww)) / (ZOOM * 100));
	Cy = floor((double)((player.y * ZOOM) + y + -(wh)) / (ZOOM * 100));

	CC = &ChunkMap[Cy][Cx];

	Tx = (int)floor((double)((player.x * ZOOM) + x + -ww) / (ZOOM)) % 100;
	Ty = (int)floor((double)((player.y * ZOOM) + y + -wh) / (ZOOM)) % 100;

	if (Tx < 0)
		Tx += 100;
	if (Ty < 0)
		Ty += 100;
}

void	Ui::clearUi()
{
}

bool	Ui::checkButtonsClick(int x, int y)
{
	t_menus& cmenu = menus[MENUID];
	for (int i = 0; i < menus[MENUID].v_buttons.size(); i++)
	{
		if (menus[MENUID].v_buttons[i].hasClicked(x, y))
			return (true);
	}
	return (false);
}

void	Ui::loadInGameUi()
{

}

void	drawMenu()
{
	// ====================== menu background ===========================
	for (int i = 0; i < UI.menus[MENUID].blocks.size(); i++)
	{
		SDL_Color& c = UI.menus[MENUID].colours[i];
		SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
		SDL_RenderFillRect(renderer, &UI.menus[MENUID].blocks[i]);

	}
	for (int i = 0; i < UI.menus[MENUID].v_buttons.size(); i++)
	{
		UI.menus[MENUID].v_buttons[i].drawButton();
	}
}

void	Ui::drawUi()
{
	SDL_Rect rect;
	// ====================== tool bar background ===========================
	rect = { WINDOW_WIDTH / 2 - 250, WINDOW_HEIGHT - 50, 500, 50 };
	SDL_SetRenderDrawColor(renderer, 54, 48, 38, 0);
	SDL_RenderFillRect(renderer, &rect);

	// ====================== tool bar selector ===========================
	rect = { WINDOW_WIDTH / 2 - 250 + (50 * player.m_TBSelected), WINDOW_HEIGHT - 50, 50, 50 };
	SDL_SetRenderDrawColor(renderer, 121, 107, 86, 0);
	SDL_RenderDrawRect(renderer, &rect);

	for (int i = 99; i < 110; i++)
	{
		rect = { WINDOW_WIDTH / 2 - 250 + (50 * (i - 100)), WINDOW_HEIGHT - 50, 50, 50 };
		if (player.a_invontory[i])
			SDL_RenderCopy(renderer, ITEM_BASE[player.a_invontory[i]->m_id].texture, NULL, &rect);
	}
	if (displayInv)
		drawInv();
	if (displaySelected)
		drawSelected();

	drawMenu();
}

void	Ui::drawInv()
{
	SDL_Rect rect;
	// ====================== inv background ===========================
	rect = { WINDOW_WIDTH / 2 - 250, WINDOW_HEIGHT - 550, 500, 500 };
	SDL_SetRenderDrawColor(renderer, 54, 48, 38, 0);
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 44, 38, 28, 0);
	int i = 0;
	for (int oy = 0; oy < 10; oy++)
	{
		for (int ox = 0; ox < 10; ox++)
		{
			rect = { WINDOW_WIDTH / 2 - 245 + (ox * 50), WINDOW_HEIGHT - 545 + (oy * 50), 40, 40 };
			SDL_RenderFillRect(renderer, &rect);
			if (player.a_invontory[i])
				SDL_RenderCopy(renderer, ITEM_BASE[player.a_invontory[i]->m_id].texture, NULL, &rect);
			i++;
		}
	}
	if (mouseItem != NULL)
	{
		int	x, y;
		SDL_GetMouseState(&x, &y);

		rect = { x - 20, y - 20, 40, 40 };
		SDL_RenderCopy(renderer, ITEM_BASE[mouseItem->m_id].texture, NULL, &rect);
	}
}

void	drawText(int x, int y, string Message, int size)
{
	TTF_Font* font = TTF_OpenFont("font.ttf", size);

	if (!font)
	{
		std::cout << "Couldn't find/init open ttf font." << std::endl;
		return;
	}

	SDL_Color TextColor = { 255, 255, 255, 0 };

	SDL_Surface* TextSurface = TTF_RenderText_Solid(font, Message.c_str(), TextColor);
	SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);

	SDL_Rect TextRect = { x, y, TextSurface->w, TextSurface->h };

	SDL_RenderCopy(renderer, TextTexture, NULL, &TextRect);

	SDL_FreeSurface(TextSurface);
	SDL_DestroyTexture(TextTexture);
	TTF_CloseFont(font);
}

void	Ui::drawSelected()
{
	if (CC == NULL)
		return;

	// ====================== background ===========================
	SDL_Rect rect;
	rect = { WINDOW_WIDTH - 300, 0, 300, 400 };
	SDL_SetRenderDrawColor(renderer, 54, 48, 38, 0);
	SDL_RenderFillRect(renderer, &rect);
	rect = { WINDOW_WIDTH - 300, 0, 300, 35 };
	SDL_SetRenderDrawColor(renderer, 27, 24, 16, 0);
	SDL_RenderFillRect(renderer, &rect);

	std::string Message;

	Message = "Moist: ";
	Message += std::to_string(CC->moist[Ty][Tx]) + "%";
	drawText(WINDOW_WIDTH - 290, 40, Message, 20);

	if (CC->PlantMap.find(Ty) != CC->PlantMap.end() &&
		CC->PlantMap[Ty].find(Tx) != CC->PlantMap[Ty].end())
	{
		drawText(WINDOW_WIDTH - 290, 0, CC->PlantMap[Ty][Tx].m_name, 25);

		if (CC->PlantMap[Ty][Tx].m_type != 0)
		{
			Message = "Fert: ";
			Message += std::to_string(CC->fert[Ty][Tx]) + "%";
			drawText(WINDOW_WIDTH - 290, 60, Message, 20);
			Message = "Growth: ";
			Message += std::to_string(CC->PlantMap[Ty][Tx].m_currentGrowth);//std::to_string((CC->PlantMap[Ty][Tx].m_currentGrowth / CC->PlantMap[Ty][Tx].m_maxGrowth * 10 + 10) * (-CC->PlantMap[Ty][Tx].b_cut + 1)) + "%";
			if (CC->PlantMap[Ty][Tx].b_cut)
				Message = "Harvested";
			drawText(WINDOW_WIDTH - 290, 80, Message, 20);
		}
	}
	else
	{
		drawText(WINDOW_WIDTH - 290, 0, "Ground", 25);
	}
}