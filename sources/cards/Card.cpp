#include <iostream>
#include <string>
#include "cards/Card.hpp"
#include "renderer/print.hpp"

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
				for (int i = 0; i < cost; i++)
					std::cout << bold << ::get_color(color) << "*" << End();

				std::cout << " " << End();
			}
		}

		std::cout << End(1);
	}

	std::cout << bold << "Type: " << ::reset << ::get_color(get_color()) << get_full_type() << End(1);
}
