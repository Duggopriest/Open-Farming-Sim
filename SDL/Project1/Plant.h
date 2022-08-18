#pragma once
class Plant
{
	public:
		Plant();
		unsigned char	m_type;
		unsigned char	m_maxGrowth;
		unsigned char	m_currentGrowth;
		bool			b_cut;

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
