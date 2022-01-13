#include "cards/lands/Swamp.hpp"

Swamp::Swamp(): Land() {}

Swamp::~Swamp() {}

std::string Swamp::get_full_type() const
{
	return Land::get_full_type() + " - Swamp";
}

Card::Color Swamp::get_color() const
{
	return Color::Black;
}

std::string Swamp::get_name() const
{
	return "Swamp";
}

std::string Swamp::get_description() const
{
	return "";
}

Card* Swamp::clone() const
{
	return new Swamp(*this);
}
