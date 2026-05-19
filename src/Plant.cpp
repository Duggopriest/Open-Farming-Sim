#include "Plant.h"

Plant::Plant()
{
	m_type = 0;
	m_name = "Ploughed Dirt";
	m_currentGrowth = 0;
	m_maxGrowth = 1;
	b_cut = 0;
	m_x = -1;
	m_y = -1;
}

Wheat::Wheat()
{
	m_type = 1;
	m_name = "Wheat";
	m_currentGrowth = 0;
	m_maxGrowth = 100;
	b_cut = 0;
	m_x = -1;
	m_y = -1;
}