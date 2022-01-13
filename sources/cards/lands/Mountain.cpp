#include "cards/lands/Mountain.hpp"

Mountain::Mountain(): Land() {}

Mountain::~Mountain() {}

std::string Mountain::get_full_type() const
{
	return Land::get_full_type() + " - Mountain";
}

Card::Color Mountain::get_color() const
{
	return Color::Red;
}

std::string Mountain::get_name() const
{
	return "Mountain";
}

std::string Mountain::get_description() const
{
	return "";
}

Card* Mountain::clone() const
{
	return new Mountain(*this);
}
