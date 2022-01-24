#include "players/Player.hpp"
#include "Game.hpp"
#include "renderer/print.hpp"
#include "utils/utils.hpp"
#include "cards/Spell.hpp"

Player::Player(): m_name(""), m_health(20), m_alive(true), m_freezed(false), m_rage(false) {}

void Player::reset_player()
{
	deck.clear();
	library.clear();
	hand.clear();
	lands.clear();
	creatures.clear();
	graveyard.clear();
	m_health = 20;
	m_alive = true;
	m_freezed = false;
	m_rage = false;
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

void Player::freeze()
{
	m_freezed = true;
}

void Player::rage()
{
	m_rage = true;
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
	std::cout << cyan << "[INFO] " << reset << "You played " << get_color(card.get_color()) << italic << card.get_name() << reset << "." << End(2);

	if (card.get_type() == Card::Type::Creature)
	{
		creatures.add(card);
		creatures.back().spawn();
	}

	else if (card.get_type() == Card::Type::Spell)
	{
		((Spell&)card).apply_effect();
		graveyard.add(card);
	}

	else
		lands.add(card);

	hand.remove(card);
}

bool Player::is_card_playable(const Card& card)
{
	Card::Cost cost_map = card.get_cost();
	Resources resources_map = get_resources();

	for (auto& [color, cost] : cost_map)
		if (!(color == Card::Color::Colorless) && cost > 0)
		{
			if (cost > resources_map[color])
				return false;

			else
			{
				resources_map[color] -= cost;
				resources_map[Card::Color::Colorless] -= cost;
			}
		}

	if (cost_map[Card::Color::Colorless] > resources_map[Card::Color::Colorless])
		return false;

	return true;
}

bool Player::engage_lands(const Card& card)
{
	Card::Cost cost_map = card.get_cost();
	Resources resources_map = get_resources();
	Resources to_engage =
	{
		{ Card::Color::Colorless,	0 },
		{ Card::Color::White,		0 },
		{ Card::Color::Blue,		0 },
		{ Card::Color::Black,		0 },
		{ Card::Color::Red,			0 },
		{ Card::Color::Green,		0 }
	};

	for (auto& [color, cost] : cost_map)
		if (!(color == Card::Color::Colorless) && cost > 0)
		{
			if (cost > resources_map[color])
			{
				std::cout << red << "You don't have enough lands." << End(2);
				return false;
			}

			else
			{
				resources_map[color] -= cost;
				resources_map[Card::Color::Colorless] -= cost;
				to_engage[color] += cost;
			}
		}

	if (cost_map[Card::Color::Colorless] > resources_map[Card::Color::Colorless])
	{
		std::cout << red << "You don't have enough lands." << End(2);
		return false;
	}

	else
	{
		resources_map[Card::Color::Colorless] -= cost_map[Card::Color::Colorless];
		to_engage[Card::Color::Colorless] += cost_map[Card::Color::Colorless];
	}

	std::vector<size_t> already_engaged_indexes;

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

		int res = choice(choices, colors, { "- Back -" });

		if (res == indexes.size())
		{
			for (auto& index : already_engaged_indexes)
				lands[index].disengage();

			std::cout << red << "You cancelled your action." << End(2);
			return false;
		}

		else if (to_engage[lands[indexes.at(res)].get_color()] > 0)
		{
			lands[indexes.at(res)].engage();
			to_engage[lands[indexes.at(res)].get_color()] -= 1;
			already_engaged_indexes.push_back(indexes.at(res));
		}

		else if (to_engage[Card::Color::Colorless] > 0)
		{
			lands[indexes.at(res)].engage();
			to_engage[Card::Color::Colorless] -= 1;
			already_engaged_indexes.push_back(indexes.at(res));
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
			std::cout << get_color(creature.get_color()) << creature.get_name() << " (" << creature.get_power() << "/" << creature.get_toughness() << ")  " << End();

	std::cout << End(1);
}

void Player::begin_turn()
{
	std::cout << End(1) << magenta << bold << "--=( " + get_name() + "'s turn )=--" << End(2);
	reset_creatures();
	get_opponent().reset_creatures();
	draw_card();
	disengage_cards();
	m_freezed = false;
	get_opponent().m_freezed = false;

	for (auto& creature : creatures)
		creature.special_ability();

	for (auto& creature : get_opponent().creatures)
		creature.special_ability();

	if (m_rage)
	{
		m_rage = false;

		for (auto& creature : creatures)
			creature.modify_power(1);
	}

	if (get_opponent().m_rage)
	{
		get_opponent().m_rage = false;

		for (auto& creature : get_opponent().creatures)
			creature.modify_power(1);
	}

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
			if (hand[i].get_type() == Card::Type::Creature || hand[i].get_type() == Card::Type::Spell)
			{
				if (is_card_playable(hand[i]))
					hand_names.push_back(to_str(underline) + hand[i].get_name() + to_str(no_underline) + " (" + to_str(hand[i].get_type()) + ")");

				else
					hand_names.push_back(hand[i].get_name() + " (" + to_str(hand[i].get_type()) + ")");
			}

			else
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

		if (hand[res].get_type() == Card::Type::Creature || hand[res].get_type() == Card::Type::Spell)
		{
			hand[res].print();
			int res_2 = choice({ "- Play card -", "- Back -" }, { green, red });

			if (res_2 == 0 && engage_lands(hand[res]))
				play_card(hand[res]);
		}

		else
			play_card(hand[res]);
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
				if (creatures[i].is_attacking())
					attacking_creatures_choice.push_back(to_str(underline) + creatures[i].get_name() + to_str(no_underline) + (creatures[i].is_engaged() ? " (E)" : ""));

				else
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

	get_opponent().block();

	// TODO: Change order of targets

	std::vector<std::string> attacking_order_choice;
	std::vector<std::string_view> attacking_order_color;

	std::vector<Creature*> new_targets;
	int res;

	for (auto& creature : creatures)
		if (creature.is_attacking())
		{
			if (creature.m_targets.size() > 1)
			{
				for (auto& target : creature.m_targets)
				{
					attacking_order_choice.push_back(target->get_name());
					attacking_order_color.push_back(get_color(target->get_color()));
				}

				while (new_targets.size() < creature.m_targets.size())
				{
					std::cout << End(1) << magenta << bold << get_name() << reset << ", choose the #" << new_targets.size() + 1 << " creature you want to attack." << End(1);
					res = choice(attacking_order_choice, attacking_order_color);
					new_targets.push_back(creature.m_targets.at(res));
					attacking_order_choice.erase(attacking_order_choice.begin() + res);
					attacking_order_color.erase(attacking_order_color.begin() + res);
				}

				creature.m_targets = new_targets;
			}
		}

	for (auto& creature : creatures)
		if (creature.is_attacking())
			creature.apply_attack();

	check_creatures_death();
	get_opponent().check_creatures_death();
}

void Player::block()
{
	if (creatures.size() > 0 && !m_freezed)
		while (true)
		{
			std::vector<std::string> blocking_choices;
			std::vector<std::string_view> blocking_colors;
			std::vector<size_t> blocking_indexes;

			std::vector<std::string> reach_blocking_choices;
			std::vector<std::string_view> reach_blocking_colors;
			std::vector<size_t> reach_blocking_indexes;

			std::vector<std::string> no_flying_to_block_choices;
			std::vector<std::string_view> no_flying_to_block_colors;
			std::vector<size_t> no_flying_to_block_indexes;

			std::vector<std::string> to_block_choices;
			std::vector<std::string_view> to_block_colors;
			std::vector<size_t> to_block_indexes;

			for (int i = 0; i < creatures.size(); i++)
			{
				if (creatures[i].is_blocking())
					blocking_choices.push_back(to_str(underline) + creatures[i].get_name() + to_str(no_underline));
				else
					blocking_choices.push_back(creatures[i].get_name());

				blocking_colors.push_back(get_color(creatures[i].get_color()));
				blocking_indexes.push_back(i);

				if (creatures[i].has(Creature::Capacity::Reach))
				{
					if (creatures[i].is_blocking())
						reach_blocking_choices.push_back(to_str(underline) + creatures[i].get_name() + to_str(no_underline));
					else
						reach_blocking_choices.push_back(creatures[i].get_name());

					reach_blocking_colors.push_back(get_color(creatures[i].get_color()));
					reach_blocking_indexes.push_back(i);
				}
			}

			for (int i = 0; i < get_opponent().creatures.size(); i++)
				if (get_opponent().creatures[i].is_attacking() && !get_opponent().creatures[i].has(Creature::Capacity::Unblockable))
				{
					to_block_choices.push_back(get_opponent().creatures[i].get_name());
					to_block_colors.push_back(get_color(get_opponent().creatures[i].get_color()));
					to_block_indexes.push_back(i);

					if (!get_opponent().creatures[i].has(Creature::Capacity::Flying))
					{
						no_flying_to_block_choices.push_back(get_opponent().creatures[i].get_name());
						no_flying_to_block_colors.push_back(get_color(get_opponent().creatures[i].get_color()));
						no_flying_to_block_indexes.push_back(i);
					}
				}

			if (to_block_choices.size() <= 0 || (reach_blocking_choices.size() == 0 && no_flying_to_block_choices.size() == 0))
				break;

			std::cout << magenta << bold << get_name() << reset << ", select creatures to block "
				<< magenta << bold << get_opponent().get_name() << reset << "'s attack:" << End(1);

			auto& final_blocking_choices = no_flying_to_block_choices.size() == 0 ? reach_blocking_choices : blocking_choices;
			auto& final_blocking_colors = no_flying_to_block_choices.size() == 0 ? reach_blocking_colors : blocking_colors;
			auto& final_blocking_indexes = no_flying_to_block_choices.size() == 0 ? reach_blocking_indexes : blocking_indexes;

			int res = choice(final_blocking_choices, final_blocking_colors, { "- Next -" });

			if (res == final_blocking_choices.size())
				break;

			if (creatures[final_blocking_indexes[res]].is_blocking())
			{
				std::cout << cyan << "[INFO] " << reset << "You cancelled the blocking of this creature." << End(2);
				creatures[final_blocking_indexes[res]].will_not_block();
			}

			else
			{
				std::cout << "Select the creature you want to block:" << End(1);

				auto& final_to_block_choices = creatures[final_blocking_indexes[res]].has(Creature::Capacity::Reach) ? to_block_choices : no_flying_to_block_choices;
				auto& final_to_block_colors = creatures[final_blocking_indexes[res]].has(Creature::Capacity::Reach) ? to_block_colors : no_flying_to_block_colors;
				auto& final_to_block_indexes = creatures[final_blocking_indexes[res]].has(Creature::Capacity::Reach) ? to_block_indexes : no_flying_to_block_indexes;

				int res_2 = choice(final_to_block_choices, final_to_block_colors, { "- Back -" });

				if (res_2 < final_to_block_choices.size())
				{
					std::cout << cyan << "[INFO] " << reset << italic << final_blocking_colors[res] << final_blocking_choices[res] << reset <<
						" will block " << italic << final_to_block_colors[res_2] << final_to_block_choices[res_2] << reset << "." << End(2);

					creatures[final_blocking_indexes[res]].will_block(get_opponent().creatures[final_to_block_indexes[res_2]]);
				}
			}
		}
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

