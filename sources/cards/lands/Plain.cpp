#include "cards/lands/Plain.hpp"

Plain::Plain(): Land() {}

Plain::~Plain() {}

std::string Plain::get_full_type() const
{
	return Land::get_full_type() + " - Plain";
}

Card::Color Plain::get_color() const
{
	return Color::White;
}

std::string Plain::get_name() const
{
	return "Plain";
}

std::string Plain::get_description() const
{
	return "";
}

Card* Plain::clone() const
{
	return new Plain(*this);
}
