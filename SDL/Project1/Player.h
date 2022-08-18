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

		Item	*a_toolBelt[10];
		Item	*a_invontory[100];


		array< unsigned char, 10 > sa_toolBelt;
		array< unsigned char, 100 > sa_invontory;
		

		bool	insertItemInv(Item* newItem);
		bool	insertItemToolBelt(Item* newItem);
		void	drawPlayer();

		template<class T>
		void pack(T& pack)
		{
			pack(x, y, angle, speed, sa_toolBelt, sa_invontory);
		};
};


#endif