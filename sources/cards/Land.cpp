#include <iostream>
#include "cards/Land.hpp"
#include "renderer/print.hpp"

Land::Land(): Card() {}

Land::~Land() {}

Card::Type Land::get_type() const
{
	return Type::Land;
}

std::string Land::get_full_type() const
{
	return "Land";
}

Card::Cost Land::get_cost() const
{
	return {};
}

void Land::print() const
{
	Card::print();
	std::cout << bold << "Description: " << ::reset << ::get_color(get_color()) << get_description() << End(1);
}
