#pragma once
class Plant
{
	public:
		unsigned char	m_type;
		unsigned char	m_maxGrowth;
		unsigned char	m_currentGrowth;
};

class Wheat : public Plant
{
	public:
		Wheat();
};
