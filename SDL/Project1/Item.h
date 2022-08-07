#pragma once

#include <string>

class Item
{
	public:
		Item();

		unsigned char	m_id;
		std::string		m_name;
		unsigned char	m_quanity;
	
		virtual void	doClick(int x, int y);
};

class Plow_Item : public Item
{
	public:
		Plow_Item();

		void	doClick(int x, int y);
};

class Wheat_Seed_Item : public Item
{
	public:
		Wheat_Seed_Item();

		void	doClick(int x, int y);
};