#include <iostream>
#include <string>
#include "cards/Card.hpp"
#include "renderer/Renderer.hpp"

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
	Renderer::print("Name: ", Renderer::Color::White, true);
	Renderer::print(get_name(), Renderer::get_color(get_color()));
	Renderer::new_lines();

	if (!get_cost().empty())
	{
		Renderer::print("Cost: ", Renderer::Color::White, true);

		for (auto& [color, cost] : get_cost())
		{
			if (color == Color::Colorless)
				Renderer::print(std::to_string(cost) + " ", Renderer::Color::White);

			else
			{
				for (int i = 0; i < cost; i++)
					Renderer::print("*", Renderer::get_color(color), true);

				Renderer::print(" ");
			}
		}

		Renderer::new_lines();
	}

	Renderer::print("Type: ", Renderer::Color::White, true);
	Renderer::print(get_full_type(), Renderer::get_color(get_color()));
	Renderer::new_lines();

	Renderer::print("Description: ", Renderer::Color::White, true);
	Renderer::print(get_description(), Renderer::get_color(get_color()));
	Renderer::new_lines();
}
