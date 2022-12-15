#pragma once

#include <string>

class Item
{
	public:
		Item();

		unsigned char	m_id;
		std::string		m_name;
		bool			m_stackable;
		unsigned char	m_quanity;
		unsigned char	m_classType;

		Item& operator=(const Item& src);
	
		virtual void	doClick();
};


// =================================== Tools
class Plow_Item : public Item
{
	public:
		Plow_Item();

		void	doClick();
};

class Scythe_Item : public Item
{
public:
	Scythe_Item();

	void	doClick();
};

// =================================== Plant items
class Wheat_Seed_Item : public Item
{
	public:
		Wheat_Seed_Item();

		void	doClick();
};

class Wheat_Item : public Item
{
public:
	Wheat_Item();

	void	doClick();
};