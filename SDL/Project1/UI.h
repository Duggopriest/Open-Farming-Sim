#pragma once

#include <vector>

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
		vector<Button> v_buttons;

		bool	checkButtonsClick(int x, int y);
};

