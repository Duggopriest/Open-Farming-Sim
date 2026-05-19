#ifndef PLAYER_H
# define PLAYER_H

#include <array>
#include "Item.h"
#include "msgpack.hpp"

using std::array;

class Player
{
	public:
		Player();
		~Player();

		Player &operator=(const Player& src);

		double	x;
		double	y;
		double	speed;

		double angle;

		unsigned char	m_TBSelected;

		Item	*a_invontory[110];


		array< unsigned char, 110 > sa_invontory;
		

		bool	insertItemInv(Item* newItem);
		void	drawPlayer();

		template<class T>
		void pack(T& pack)
		{
			pack(x, y, angle, speed, sa_invontory);
		};
};


#endif