#include "Player.h"
#include "Header.hpp"

Player::Player()
{
	x = 250;
	y = 250;
	angle = 0;
	m_TBSelected = 0;

	for (int i = 0; i < 110; i++)
	{
		a_invontory[i] = NULL;
	}
}

Player::~Player()
{

	for (int i = 0; i < 110; i++)
	{
		delete a_invontory[i];
	}
}

Player& Player::operator=(const Player& src)
{
	*this = src;
	return (*this);
}

bool	Player::insertItemInv(Item* newItem)
{
	int i = 0;
	while (a_invontory[i] && i < 110)
		i++;

	if (i >= 110)
		return (false);

	a_invontory[i] = newItem;
	return (true);
}

void	Player::drawPlayer()
{
	SDL_Rect dstrect;
	dstrect.h = 51;
	dstrect.w = 51;
	dstrect.x = WINDOW_WIDTH / 2 - 25;
	dstrect.y = WINDOW_HEIGHT / 2 - 25;


	SDL_Point center;
	center.x = 25;
	center.y = 25;



	SDL_RenderCopyEx(renderer,
		Player_Base[1].texture,
		NULL,
		&dstrect,
		angle,
		&center,
		SDL_FLIP_NONE);
}