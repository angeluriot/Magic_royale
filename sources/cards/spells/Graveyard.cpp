#include "cards/spells/Graveyard.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"
#include "utils/utils.hpp"
#include <algorithm>

Graveyard::Graveyard(): Spell() {}

Graveyard::~Graveyard() {}

Card::Color Graveyard::get_color() const
{
	return Color::Black;
}

std::string Graveyard::get_name() const
{
	return "Graveyard";
}

std::string Graveyard::get_description() const
{
	return "Resurrects the last two cards of the graveyard.";
}

Card::Cost Graveyard::get_cost() const
{
	return
	{
		{ Color::Colorless, 3 },
		{ Color::Black, 2 }
	};
}

void Graveyard::apply_effect()
{
	std::vector<Creature*> creatures;
	std::vector<std::string> shown;
	int nb = 0;

	for (auto& card : m_owner->graveyard)
		if (card.get_type() == Card::Type::Creature)
			creatures.push_back((Creature*)(&card));

	std::reverse(creatures.begin(), creatures.end());

	for (auto creature : creatures)
	{
		creature->full_reset();
		shown.push_back(to_str(italic) + to_str(::get_color(creature->get_color())) + creature->get_name() + to_str(::reset));
		m_owner->creatures.add(*creature);
		m_owner->graveyard.remove(*creature);

		if (nb++ == 1)
			break;
	}

	if (shown.size() == 2)
		std::cout << cyan << "[INFO]" << ::reset << " Resurrected " << shown[0] << " and " << shown[1] << "." << End(2);

	else if (shown.size() == 1)
		std::cout << cyan << "[INFO]" << ::reset << " Resurrected " << shown[0] << "." << End(2);

	else
		std::cout << cyan << "[INFO]" << ::reset << " The graveyard is empty so no card was resurrected." << End(2);
}

Card* Graveyard::clone() const
{
	return new Graveyard(*this);
}
