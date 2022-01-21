#include "players/Player.hpp"
#include "Game.hpp"
#include "renderer/print.hpp"
#include "utils/utils.hpp"

Player::Player(): m_name(""), m_health(20), m_alive(true) {}

void Player::revive()
{
	m_alive = true;
}

bool Player::is_alive()
{
	return m_alive;
}

bool Player::can_attack()
{
	for (auto& creature : creatures)
		if (creature.can_attack())
			return true;

	return false;
}

bool Player::can_block()
{
	return creatures.size() > 0;
}

std::string Player::get_name() const
{
	return m_name;
}

void Player::set_name(const std::string& name)
{
	m_name = name;
}

int Player::get_health() const
{
	return m_health;
}

void Player::set_health(int health)
{
	m_health = health;

	if (m_health <= 0)
	{
		m_alive = false;
		m_health = 0;
	}
}

void Player::reduce_health(int amount)
{
	set_health(m_health - amount);
}

Player::Resources Player::get_resources()
{
	Resources res =
	{
		{ Card::Color::Colorless, 0 },
		{ Card::Color::White, 0 },
		{ Card::Color::Blue, 0 },
		{ Card::Color::Black, 0 },
		{ Card::Color::Red, 0 },
		{ Card::Color::Green, 0 }
	};

	for (auto& land : lands)
		if (!land.is_engaged())
		{
			res[Card::Color::Colorless]++;
			res[land.get_color()]++;
		}

	return res;
}

void Player::remove_target(const Creature& target)
{
	for (auto& creature : creatures)
		creature.remove_target(target);
}

void Player::create_deck(const PtrList<Card>& deck)
{
	this->deck = deck;

	for (auto& card : this->deck)
		card.set_owner(*this);

	library = this->deck;

	// Shuffle the library
	for (int i = 0; i < library.size(); i++)
		library.swap(i, (size_t)random_int(0, (int)this->deck.size()));

	for (int i = 0; i < 6; i++)
		draw_card();
}

void Player::play_card(const Card& card)
{
	if (card.get_type() == Card::Type::Creature)
	{
		creatures.add(card);
		creatures.back().spawn();
	}

	else
		lands.add(card);

	hand.remove(card);
	// TODO : set_player()
}

bool Player::is_card_playable(const Card& card)
{
	Card::Cost cost_map = card.get_cost();
	Resources resources_map = get_resources();
	Resources to_engage =
	{
		{ Card::Color::Colorless, 	0 },
		{ Card::Color::White, 		0 },
		{ Card::Color::Blue, 		0 },
		{ Card::Color::Black, 		0 },
		{ Card::Color::Red, 		0 },
		{ Card::Color::Green, 		0 }
	};

	for (auto& [color, cost] : cost_map)
		if (!(color == Card::Color::Colorless) && cost > 0)
		{
			if (cost > resources_map[color])
				return false;

			else
			{
				resources_map[color] -= cost;
				resources_map[Card::Color::Colorless] -= cost;
				to_engage[color] += cost;
			}
		}

	if (cost_map[Card::Color::Colorless] > resources_map[Card::Color::Colorless])
		return false;

	else
	{
		resources_map[Card::Color::Colorless] -= cost_map[Card::Color::Colorless];
		to_engage[Card::Color::Colorless] += cost_map[Card::Color::Colorless];
	}

	while (to_engage[Card::Color::White] > 0 || to_engage[Card::Color::Blue] > 0 || to_engage[Card::Color::Black] > 0 ||
		to_engage[Card::Color::Red] > 0 || to_engage[Card::Color::Green] > 0 || to_engage[Card::Color::Colorless] > 0)
	{
		std::cout << "You have to engage" << End();
		bool is_first = true;

		if (to_engage[Card::Color::White] > 0)
		{
			if (!is_first)
				std::cout << ",";

			std::cout << " " << to_engage[Card::Color::White] << white << " white " << (to_engage[Card::Color::White] > 1 ? "lands" : "land") << End();
			is_first = false;
		}

		if (to_engage[Card::Color::Blue] > 0)
		{
			if (!is_first)
			{
				if (to_engage[Card::Color::Black] == 0 && to_engage[Card::Color::Red] == 0 &&
					to_engage[Card::Color::Green] == 0 && to_engage[Card::Color::Colorless] == 0)
					std::cout << " and ";
				else
					std::cout << ",";
			}

			std::cout << " " << to_engage[Card::Color::Blue] << blue << " blue " << (to_engage[Card::Color::Blue] > 1 ? "lands" : "land") << End();
			is_first = false;
		}

		if (to_engage[Card::Color::Black] > 0)
		{
			if (!is_first)
			{
				if (to_engage[Card::Color::Red] == 0 && to_engage[Card::Color::Green] == 0 && to_engage[Card::Color::Colorless] == 0)
					std::cout << " and ";
				else
					std::cout << ",";
			}

			std::cout << " " << to_engage[Card::Color::Black] << gray << " black " << (to_engage[Card::Color::Black] > 1 ? "lands" : "land") << End();
			is_first = false;
		}

		if (to_engage[Card::Color::Red] > 0)
		{
			if (!is_first)
			{
				if (to_engage[Card::Color::Green] == 0 && to_engage[Card::Color::Colorless] == 0)
					std::cout << " and ";
				else
					std::cout << ",";
			}

			std::cout << " " << to_engage[Card::Color::Red] << red << " red " << (to_engage[Card::Color::Red] > 1 ? "lands" : "land") << End();
			is_first = false;
		}

		if (to_engage[Card::Color::Green] > 0)
		{
			if (!is_first)
			{
				if (to_engage[Card::Color::Colorless] == 0)
					std::cout << " and ";
				else
					std::cout << ",";
			}

			std::cout << " " << to_engage[Card::Color::Green] << green << " green " << (to_engage[Card::Color::Green] > 1 ? "lands" : "land") << End();
			is_first = false;
		}

		if (to_engage[Card::Color::Colorless] > 0)
		{
			if (!is_first)
				std::cout << " and";

			std::cout << " " << to_engage[Card::Color::Colorless] << (to_engage[Card::Color::Colorless] > 1 ? " lands" : " land") << " of the color you want." << End();
			is_first = false;
		}

		std::cout << End(2) << "Choose a land to engage:" << End(1);
		std::vector<std::string> choices;
		std::vector<std::string_view> colors;
		std::vector<size_t> indexes;

		for (int i = 0; i < lands.size(); i++)
			if (!lands[i].is_engaged())
			{
				choices.push_back(lands[i].get_name());
				colors.push_back(get_color(lands[i].get_color()));
				indexes.push_back(i);
			}

		// TODO : Back button
		int res = choice(choices, colors/*, { "- Back -" }*/);

		if (to_engage[lands[indexes.at(res)].get_color()] > 0)
		{
			lands[indexes.at(res)].engage();
			to_engage[lands[indexes.at(res)].get_color()] -= 1;
		}

		else if (to_engage[Card::Color::Colorless] > 0)
		{
			lands[indexes.at(res)].engage();
			to_engage[Card::Color::Colorless] -= 1;
		}

		else
			std::cout << red << "You don't need to engage this land." << End(2);
	}

	return true;
}

void Player::show_board()
{
	Resources enemy_resources_map = get_opponent().get_resources();
	Resources resources_map = get_resources();
	std::cout << "Enemy HP: " << green << get_opponent().get_health() << End(1);

	std::cout << "Available lands: " << white << enemy_resources_map[Card::Color::White] << End();
	std::cout << " " << blue << enemy_resources_map[Card::Color::Blue] << End();
	std::cout << " " << gray << enemy_resources_map[Card::Color::Black] << End();
	std::cout << " " << red << enemy_resources_map[Card::Color::Red] << End();
	std::cout << " " << green << enemy_resources_map[Card::Color::Green] << End(1);

	std::cout << "Enemy creatures: " << End();
	get_opponent().show_creatures();
	std::cout << End(1) << "Your creatures: " << End();
	show_creatures();

	std::cout << "Available lands: " << white << resources_map[Card::Color::White] << End();
	std::cout << " " << blue << resources_map[Card::Color::Blue] << End();
	std::cout << " " << gray << resources_map[Card::Color::Black] << End();
	std::cout << " " << red << resources_map[Card::Color::Red] << End();
	std::cout << " " << green << resources_map[Card::Color::Green] << End(1);

	std::cout << "Your HP: " << green << get_health() << End(2);
}

void Player::show_creatures()
{
	for (auto& creature : creatures)
		if (creature.is_alive())
			std::cout << get_color(creature.get_color()) << creature.get_name() << " (" << creature.get_power() << ", " << creature.get_toughness() << ")  " << End();

	std::cout << End(1);
}

void Player::begin_turn()
{
	std::cout << End(1) << magenta << bold << "--=( " + get_name() + "'s turn )=--" << End(2);
	reset_creatures();
	get_opponent().reset_creatures();
	draw_card();

	if (m_alive)
	{
		disengage_cards();

		std::cout << End(1) << yellow << bold << "--=( Main Phase )=--" << End(2);
		main_phase();

		if (can_attack())
		{
			std::cout << End(1) << yellow << bold << "--=( Combat Phase )=--" << End(2);
			combat_phase();
		}

		if (get_opponent().is_alive())
		{
			if (can_attack())
			{
				std::cout << End(1) << yellow << bold << "--=( Secondary Phase )=--" << End(2);
				secondary_phase();
			}

			std::cout << End(1) << yellow << bold << "--=( End of turn )=--" << End(2);
			end_turn();
		}
	}
}

void Player::draw_card()
{
	if (library.empty())
		m_alive = false;

	else
	{
		hand.add(library.back());
		library.remove(library.back());
	}
}

void Player::disengage_cards()
{
	for (auto& creature : creatures)
		if (creature.is_engaged())
			creature.disengage();

	for (auto& land : lands)
		if (land.is_engaged())
			land.disengage();
}

void Player::main_phase()
{
	while (hand.size() > 0)
	{
		show_board();

		std::cout << "Your hand:" << End(1);
		std::vector<std::string> hand_names = {};
		std::vector<std::string_view> hand_colors = {};

		for (int i = 0; i < hand.size(); i++)
		{
			hand_names.push_back(hand[i].get_name() + " (" + to_str(hand[i].get_type()) + ")");
			hand_colors.push_back(get_color(hand[i].get_color()));
		}

		int res = choice(hand_names, hand_colors, { "- Next -", "- Quit -" });

		if (res == hand.size())
			break;

		if (res == hand.size() + 1)
		{
			quit_game();
			continue;
		}

		if (hand[res].get_type() == Card::Type::Creature)
		{
			Creature& creature = (Creature&)hand[res];

			if (!is_card_playable(creature))
				std::cout << red << "You don't have enough lands." << End(2);

			else
			{
				std::cout << cyan << "[INFO] " << reset << "You played " << get_color(creature.get_color()) <<
					italic << creature.get_name() << reset << "." << End(2);

				play_card(creature);
			}
		}

		else
		{
			std::cout << cyan << "[INFO] " << reset << "You played " << get_color(hand[res].get_color()) <<
				italic << hand[res].get_name() << reset << "." << End(2);
			play_card(hand[res]);
		}
	}

	check_creatures_death();
	get_opponent().check_creatures_death();
}

void Player::combat_phase()
{
	while (true)
	{
		show_board();

		std::vector<std::string> attacking_creatures_choice;
		std::vector<std::string_view> attacking_creatures_color;
		std::vector<size_t> indexes;

		for (size_t i = 0; i < creatures.size(); i++)
		{
			if (creatures[i].can_attack())
			{
				attacking_creatures_choice.push_back(creatures[i].get_name() + (creatures[i].is_engaged() ? " (E)" : ""));
				attacking_creatures_color.push_back(get_color(creatures[i].get_color()));
				indexes.push_back(i);
			}
		}

		std::cout << "Select a creature to attack:" << End(1);

		int res = choice(attacking_creatures_choice, attacking_creatures_color, { "- Next -", "- Quit -" });

		indexes.push_back(attacking_creatures_choice.size());
		indexes.push_back(attacking_creatures_choice.size() + 1);

		if (indexes.at(res) == attacking_creatures_choice.size())
			break;

		if (indexes.at(res) == attacking_creatures_choice.size() + 1)
		{
			quit_game();
			continue;
		}

		if (creatures[indexes.at(res)].is_attacking())
		{
			creatures[indexes.at(res)].will_not_attack();
			std::cout << cyan << "[INFO] " << reset << "You cancelled the attack of this creature." << End(2);
		}

		else
		{
			creatures[indexes.at(res)].will_attack();
			std::cout << cyan << "[INFO] " << reset << "This creature will attack." << End(2);
		}
	}

	if (get_opponent().can_block())
	{
		std::vector<std::string> blocking_creatures_choice;
		std::vector<std::string_view> blocking_creatures_color;
		std::vector<std::string> creature_to_block_choice;
		std::vector<std::string_view> creature_to_block_color;

		for (int i = 0; i < get_opponent().creatures.size(); i++)
		{
			blocking_creatures_choice.push_back(get_opponent().creatures[i].get_name());
			blocking_creatures_color.push_back(get_color(get_opponent().creatures[i].get_color()));
		}

		for (int i = 0; i < creatures.size(); i++)
			if (creatures[i].is_attacking() && creatures[i].is_blockable())
			{
				creature_to_block_choice.push_back(creatures[i].get_name());
				creature_to_block_color.push_back(get_color(creatures[i].get_color()));
			}

		if (creature_to_block_choice.size() > 0)
		{
			while (true)
			{
				std::cout << magenta << bold << get_opponent().get_name() << reset << ", select creatures to block "
					<< magenta << bold << get_name() << reset << "'s attack:" << End(1);

				int res = choice(blocking_creatures_choice, blocking_creatures_color, { "- Next -" });

				if (res == blocking_creatures_choice.size())
					break;

				if (get_opponent().creatures[res].is_blocking())
					std::cout << red << "You already selected this creature." << End(1);
					// TODO: Change target block

				else
				{
					std::cout << "Select the creature you want to block:" << End(1);
					int res_2 = choice(creature_to_block_choice, creature_to_block_color);
					get_opponent().creatures[res].will_block(creatures[res_2]);
				}
			}
		}
	}

	// TODO: Change order of targets

	for (auto& creature : creatures)
		if (creature.is_attacking())
			creature.apply_attack();

	check_creatures_death();
	get_opponent().check_creatures_death();
}

void Player::secondary_phase()
{
	main_phase();
}

void Player::end_turn()
{
	if (hand.size() > 7)
	{
		std::vector<std::string> discard_choice;
		std::vector<std::string_view> discard_color;

		for (int i = 0; i < hand.size(); i++)
		{
			discard_choice.push_back(hand[i].get_name() + " (" + to_str(hand[i].get_type()) + ")");
			discard_color.push_back(get_color(hand[i].get_color()));
		}

		while (hand.size() > 7)
		{
			std::cout << red << "You have more than 7 cards in your hand, select a card to discard:" << End(1);
			int res = choice(discard_choice, discard_color);
			graveyard.add(hand[res]);
			hand.remove(res);
		}
	}
}

void Player::play()
{
	// TODO
}

Player& Player::get_opponent() const
{
	if (&Game::players[0] == this)
		return Game::players[1];

	return Game::players[0];
}

void Player::reset_creatures()
{
	for (auto& creature : creatures)
		creature.reset();
}

void Player::check_creatures_death()
{
	std::vector<Creature*> dead_creatures;

	for (auto& creature : creatures)
		if (!creature.is_alive())
		{
			dead_creatures.push_back(&creature);
			creature.die();
		}

	for (auto& dead_creature : dead_creatures)
	{
		dead_creature->reset();
		graveyard.add(*dead_creature);
		creatures.remove(*dead_creature);
	}
}

