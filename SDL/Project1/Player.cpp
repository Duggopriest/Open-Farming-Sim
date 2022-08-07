#include "Player.h"

Player::Player()
{
	x = 250;
	y = 250;
	angle = 0;
	m_TBSelected = 0;
}

Player::~Player()
{
	for (int i = 0; i < 5; i++)
	{
		delete a_toolBelt[i];
	}
}