#include <iostream>
#include "cards/Spell.hpp"
#include "renderer/print.hpp"

Spell::Spell(): Card() {}

Spell::~Spell() {}

Card::Type Spell::get_type() const
{
	return Type::Spell;
}

std::string Spell::get_full_type() const
{
	return "Spell";
}

void Spell::print() const
{
	Card::print();
	std::cout << bold << "Description: " << ::reset << ::get_color(get_color()) << get_description() << End(1);
}
