#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "utils/PtrList.hpp"
#include "cards/lands/Land.hpp"
#include "cards/creatures/Creature.hpp"

class Player
{
private:

	PtrList<Card> m_library;
	PtrList<Card> m_hand;
	PtrList<Land> m_lands;
	PtrList<Creature> m_creatures;
	PtrList<Card> m_graveyard;
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
