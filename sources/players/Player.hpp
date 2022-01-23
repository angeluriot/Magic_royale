#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <map>
#include <stdlib.h>
#include <time.h>
#include "utils/PtrList.hpp"
#include "cards/Land.hpp"
#include "cards/Creature.hpp"

class Player
{
public:

	typedef std::map<Card::Color, int> Resources;

private:

	std::string m_name;
	int m_health;
	bool m_alive;
	bool m_freezed;
	bool m_rage;

public:

	PtrList<Card> deck;
	PtrList<Card> library;
	PtrList<Card> hand;
	PtrList<Land> lands;
	PtrList<Creature> creatures;
	PtrList<Card> graveyard;

	Player();

	void reset_player();
	bool is_alive();
	bool can_attack();
	void freeze();
	void rage();
	std::string get_name() const;
	void set_name(const std::string& name);
	int get_health() const;
	void set_health(int health);
	void reduce_health(int amount);
	Resources get_resources();
	void remove_target(const Creature& target);
	void create_deck(const PtrList<Card>& deck);
	void play_card(const Card& card);
	bool is_card_playable(const Card& card);
	bool engage_lands(const Card& card);
	void show_board();
	void show_creatures();
	void begin_turn();
	void draw_card();
	void disengage_cards();
	void main_phase();
	void combat_phase();
	void block();
	void secondary_phase();
	void end_turn();
	void play();
	Player& get_opponent() const;
	void reset_creatures();
	void check_creatures_death();
};

#endif
