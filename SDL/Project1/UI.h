#pragma once

#include <vector>
#include <SDL.h>
#include "Chunk.h"
#include <string>

using std::vector;

class Button
{
	public:
		Button();
		Button(int x, int y, int sizeX, int sizeY, void (*fun)(void), SDL_Color colour, std::string name);
		~Button();

		int	m_x;
		int	m_y;

		int	m_sizeX;
		int	m_sizeY;

		SDL_Color color;

		std::string name;

		
		SDL_Texture* TextTexture;
		SDL_Rect TextRect;

		void (*funptr)(void);
		bool	hasClicked(int x, int y);
		virtual void	onClick();
		void	drawButton();
	private:
};

typedef struct s_menus
{
	unsigned char	id;
	std::string name;
	vector<SDL_Rect> blocks;
	vector<SDL_Color> colours;
	vector<Button> v_buttons;
} t_menus;

class Ui
{
	public:
		Ui();
		~Ui();
		vector<t_menus> menus;

		bool	displayInv;


		bool	checkButtonsClick(int x, int y);

		void	clearUi();
		void	loadInGameUi();
		void	drawUi();
		void	drawInv();
};

