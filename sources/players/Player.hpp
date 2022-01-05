#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "cards/lands/Land.hpp"
#include "cards/creatures/Creature.hpp"

class Player
{
private:

	std::vector<Card*> m_deck;
	std::vector<Card*> m_hand;
	std::vector<Land*> m_lands;
	std::vector<Creature*> m_creatures;
	unsigned int m_health;

public:

	Player();
	~Player();

	void create_deck();
	void draw_card();
	void disengage_cards();
	void main_phase();
	void combat_phase();
	void secondary_phase();
	void play();
};

#endif
