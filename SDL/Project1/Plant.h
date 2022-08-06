#pragma once
class Plant
{
	public:
		unsigned char	m_type;
		unsigned char	m_currentGrowth;
		unsigned char	m_maxGrowth;
};

class Wheat : public Plant
{
	public:
		Wheat();
};
