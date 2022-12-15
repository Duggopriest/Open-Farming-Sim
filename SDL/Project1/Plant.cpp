#include "Plant.h"

Plant::Plant()
{
	m_type = 0;
	m_name = "Plant";
	m_currentGrowth = 0;
	m_maxGrowth = 1;
	b_cut = 0;
}

Wheat::Wheat()
{
	m_type = 1;
	m_name = "Wheat";
	m_currentGrowth = 0;
	m_maxGrowth = 10;
	b_cut = 0;
}