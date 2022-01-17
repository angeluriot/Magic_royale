#include <iostream>
#include <string>
#include "cards/Card.hpp"
#include "renderer/print.hpp"
#include "utils/utils.hpp"
#include "Game.hpp"

#include "cards/creatures/reds/LavaHound.hpp"
#include "cards/creatures/blacks/Pekka.hpp"
#include "cards/creatures/blues/iceWizard.hpp"
#include "cards/creatures/greens/ElectroGiant.hpp"
#include "cards/creatures/greens/Golem.hpp"
#include "cards/creatures/greens/RoyalGiant.hpp"
#include "cards/creatures/whites/MegaKnight.hpp"
#include "cards/lands/Forest.hpp"
#include "cards/lands/Island.hpp"
#include "cards/lands/Mountain.hpp"
#include "cards/lands/Plain.hpp"
#include "cards/lands/Swamp.hpp"

PtrList<Card> get_all_card()
{
	PtrList<Card> cards;

	cards.add(LavaHound());
	cards.add(Pekka());
	cards.add(IceWizard());
	cards.add(ElectroGiant());
	cards.add(Golem());
	cards.add(RoyalGiant());
	cards.add(MegaKnight());
	cards.add(Forest());
	cards.add(Island());
	cards.add(Mountain());
	cards.add(Plain());
	cards.add(Swamp());

	return cards;
}

PtrList<Card> Card::all_cards = get_all_card();

PtrList<Card> Card::get_cards_from_string(const std::vector<std::string>& cards_string)
{
	if (cards_string.size() > Game::deck_size)
		print_error("A deck can't have more than " + to_str(Game::deck_size) + " cards, please remove " +
			(cards_string.size() - Game::deck_size > 1 ? to_str(cards_string.size() - Game::deck_size) + " cards." : "a card."));

	if (cards_string.size() < Game::deck_size)
		print_error("A deck can't have less than " + to_str(Game::deck_size) + " cards, please add " +
			(Game::deck_size - cards_string.size() > 1 ? to_str(Game::deck_size - cards_string.size()) + " cards." : "a card."));

	PtrList<Card> cards;

	for (auto& card_string : cards_string)
		for (int i = 0; i < all_cards.size(); i++)
		{
			if (card_string == all_cards[i].get_name())
			{
				cards.add(all_cards[i]);
				break;
			}

			if (i == all_cards.size() - 1)
				print_error("Card not found: \"" + to_str(italic) + card_string + to_str(no_italic) + "\".");
		}

	return cards;
}

Card::Card(): m_owner(nullptr), m_engaged(false) {}

Card::~Card() {}

void Card::set_owner(Player& player)
{
	m_owner = &player;
}

void Card::engage()
{
	m_engaged = true;
}

void Card::disengage()
{
	m_engaged = false;
}

bool Card::is_engaged() const
{
	return m_engaged;
}

void Card::reset()
{
	disengage();
}

void Card::print() const
{
	std::cout << bold << "Name: " << ::reset << ::get_color(get_color()) << get_name() << End(1);

	if (!get_cost().empty())
	{
		std::cout << bold << "Cost: " << End();

		for (auto& [color, cost] : get_cost())
		{
			if (color == Color::Colorless)
				std::cout << cost << End();

			else
			{
				std::cout << " " << End();

				for (int i = 0; i < cost; i++)
					std::cout << ::get_color(color) << "*" << End();
			}
		}

		std::cout << End(1);
	}

	std::cout << bold << "Type: " << ::reset << ::get_color(get_color()) << get_full_type() << End(1);
}
