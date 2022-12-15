#include "Item.h"
#include "Header.hpp"

Item::Item()
{
	m_id = 0;
	m_name = "";
	m_stackable = 1;
	m_quanity = 0;
	m_classType = 0;
}

Item& Item::operator=(const Item& src)
{
	*this = src;
	return (*this);
}

void	Item::doClick()
{
	cout << "Default item click\n";
}


// =================================================================== Plow Item 
Plow_Item::Plow_Item()
{
	m_id = 1;
	m_name = "Plow";
	m_quanity = 1;
	m_classType = 't';
}

void Plow_Item::doClick()
{
	UI.CC->PlantMap[UI.Ty][UI.Tx] = Plant();
	UI.CC->UpdateChunk();
}


// =================================================================== Scythe Item 
Scythe_Item::Scythe_Item()
{
	m_id = 2;
	m_name = "Scythe";
	m_quanity = 1;
	m_classType = 't';
}

void Scythe_Item::doClick()
{
	if (UI.CC->PlantMap.find(UI.Ty) != UI.CC->PlantMap.end() &&
		UI.CC->PlantMap[UI.Ty].find(UI.Tx) != UI.CC->PlantMap[UI.Ty].end())
	{
		if (UI.CC->PlantMap[UI.Ty][UI.Tx].m_type != 0
			&& UI.CC->PlantMap[UI.Ty][UI.Tx].b_cut == 0
			&& UI.CC->PlantMap[UI.Ty][UI.Tx].m_currentGrowth >= 99)
		{
			player.insertItemInv(new Wheat_Item());
			UI.CC->PlantMap[UI.Ty][UI.Tx].b_cut = 1;
			UI.CC->UpdateChunk();
		}
	}
}


// =================================================================== Wheat Seed Item 
Wheat_Seed_Item::Wheat_Seed_Item()
{
	m_id = 20;
	m_name = "Wheat Seeds";
	m_quanity = 1;
	m_classType = 's';
}

void Wheat_Seed_Item::doClick()
{
	if (UI.CC->PlantMap.find(UI.Ty) != UI.CC->PlantMap.end() &&
		UI.CC->PlantMap[UI.Ty].find(UI.Tx) != UI.CC->PlantMap[UI.Ty].end())
	{
		if (UI.CC->PlantMap[UI.Ty][UI.Tx].m_type == 0)
			UI.CC->PlantMap[UI.Ty][UI.Tx] = Wheat();
		UI.CC->UpdateChunk();
	}
}


// =================================================================== Wheat Seed Item 
Wheat_Item::Wheat_Item()
{
	m_id = 40;
	m_name = "Wheat";
	m_quanity = 1;
	m_classType = 'p';
}

void Wheat_Item::doClick()
{

}