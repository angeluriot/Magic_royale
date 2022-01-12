#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <map>
#include "utils/PtrList.hpp"
#include "cards/Land.hpp"
#include "cards/Creature.hpp"

class Player
{
private:

	std::string m_name;
	PtrList<Card> m_library;
	PtrList<Card> m_hand;
	PtrList<Land> m_lands;
	PtrList<Creature> m_creatures;
	PtrList<Card> m_graveyard;
	int m_health;
	bool m_alive;

public:

	Player();

	std::string get_name() const;
	void set_name(const std::string& name);
	int get_health() const;
	void set_health(int health);
	void reduce_health(int amount);
    std::map<Card::Color, int> get_resources();
	void create_deck();
    void play_card(const Card& card);
    bool is_creature_playable(const Creature& creature);
	void draw_card();
	void disengage_cards();
	void main_phase();
	void combat_phase();
	void secondary_phase();
	void play();
	void reduce_creatures_health(int amount);
	Player& get_opponent() const;
	void add_creature(Creature* creature);
};

#endif
