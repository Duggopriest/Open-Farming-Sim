#ifndef PLAYER_H
# define PLAYER_H

#include "Item.h"

class Player
{
	public:
		Player();
		~Player();
		double	x;
		double	y;
		double	speed;

		double angle;

		unsigned char	m_TBSelected;
		Item			*a_toolBelt[5];
};


#endif // !PLAYER_H