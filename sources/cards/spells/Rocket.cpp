#include "cards/spells/Rocket.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"

Rocket::Rocket(): Spell() {}

Rocket::~Rocket() {}

Card::Color Rocket::get_color() const
{
	return Color::White;
}

std::string Rocket::get_name() const
{
	return "Rocket";
}

std::string Rocket::get_description() const
{
	return "Inflicts 6 damages to the target of your choice.";
}

Card::Cost Rocket::get_cost() const
{
	return
	{
		{ Color::Colorless, 4 },
		{ Color::White, 2 }
	};
}

void Rocket::apply_effect()
{
	std::vector<std::string> choices;
	std::vector<std::string_view> colors;

	for (auto& creature : m_owner->get_opponent().creatures)
	{
		choices.push_back(creature.get_name());
		colors.push_back(::get_color(creature.get_color()));
	}

	std::cout << "Choose a target:" << End(1);

	int res = choice(choices, colors, { "- Player -"});

	if (res == (int)choices.size())
		m_owner->get_opponent().reduce_health(6);
	else
		m_owner->get_opponent().creatures[res].modify_toughness(-6);
}

Card* Rocket::clone() const
{
	return new Rocket(*this);
}
