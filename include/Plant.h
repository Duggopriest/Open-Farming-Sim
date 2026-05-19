#pragma once

//#include "Header.hpp"

#include <string>

class Plant
{
	public:
		Plant();
		char	m_x;
		char	m_y;
		unsigned char	m_type;
		unsigned char	m_maxGrowth;
		unsigned char	m_currentGrowth;
		bool			b_cut;
		std::string		m_name;

		template<class T>
		void pack(T& pack) {
			pack(m_type, m_maxGrowth, m_currentGrowth, b_cut);
		}

};

class Wheat : public Plant
{
	public:
		Wheat();
};
