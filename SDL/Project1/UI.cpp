#include "UI.h"
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

bool	Ui::checkButtonsClick(int x, int y)
{
	for (auto it = begin(v_buttons); it != end(v_buttons); ++it) 
	{
		if (it->hasClicked(x, y))
			return (true);
	}
	return (false);
}