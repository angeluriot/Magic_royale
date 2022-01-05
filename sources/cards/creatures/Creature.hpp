#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "cards/Card.hpp"
#include <string>
#include <array>

class Creature : public Card
{
protected:

	std::string m_type;
	std::array<unsigned int, 6> m_cost;
	int m_strength;
	int m_stamina;
	bool m_can_attack;

public:

	Creature(std::string name, std::string type, std::array<unsigned int, 6> cost, int strength, int stamina);
	~Creature();
	void attack();
	void block();

};

#endif
