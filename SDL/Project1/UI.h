#pragma once

#include <vector>
#include <SDL.h>
#include "Chunk.h"

using std::vector;

class Button
{
	public:
		Button();
		Button(int x, int y, int sizeX, int sizeY);



		int	m_x;
		int	m_y;

		int	m_sizeX;
		int	m_sizeY;

		bool	hasClicked(int x, int y);
		virtual void	onClick();
	private:
};

class Ui
{
	public:
		Ui();
		~Ui();
		vector<Button> v_buttons;

		Texture_Array a_textures[10];

		bool	checkButtonsClick(int x, int y);

		void	loadInGameUi();
		void	drawUi();
};

