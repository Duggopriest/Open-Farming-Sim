#include "UI.h"
#include "Header.hpp"
#include <iostream>

Button::Button() : m_x(0), m_y(0), m_sizeX(0), m_sizeY(0)
{

}

Button::Button(int x, int y, int sizeX, int sizeY): m_x(x), m_y(y), m_sizeX(sizeX), m_sizeY(sizeY)
{

}

void	Button::onClick()
{
	std::cout << "Button Pressed\n";
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

// ====================================================================	UI

Ui::Ui()
{
	displayInv = false;
}

Ui::~Ui()
{
	for (int i = 0; i < 10; i++)
	{
		if (a_textures->texture)
			delete a_textures->texture;
	}
}

bool	Ui::checkButtonsClick(int x, int y)
{
	for (auto it = begin(v_buttons); it != end(v_buttons); ++it) 
	{
		if (it->hasClicked(x, y))
			return (true);
	}
	return (false);
}

void	Ui::loadInGameUi()
{

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

	for (int i = 0; i < 5; i++)
	{
		rect = { WINDOW_WIDTH / 2 - 250 + (50 * i), WINDOW_HEIGHT - 50, 50, 50 };
		if (player.a_toolBelt[i])
			SDL_RenderCopy(renderer, ITEM_BASE[player.a_toolBelt[i]->m_id].texture, NULL, &rect);
	}
	if (displayInv)
		drawInv();
}

void	Ui::drawInv()
{
	SDL_Rect rect;
	// ====================== inv background ===========================
	rect = { WINDOW_WIDTH / 2 - 250, WINDOW_HEIGHT - 600, 500, 500 };
	SDL_SetRenderDrawColor(renderer, 54, 48, 38, 0);
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 44, 38, 28, 0);
	int i = 0;
	for (int oy = 0; oy < 10; oy++)
	{
		for (int ox = 0; ox < 10; ox++)
		{
			rect = { WINDOW_WIDTH / 2 - 245 + (ox * 50), WINDOW_HEIGHT - 595 + (oy * 50), 40, 40 };
			SDL_RenderFillRect(renderer, &rect);
			if (player.a_invontory[i])
				SDL_RenderCopy(renderer, ITEM_BASE[player.a_invontory[i]->m_id].texture, NULL, &rect);
			i++;
		}
	}
}