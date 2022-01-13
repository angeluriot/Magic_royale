#include "cards/lands/Island.hpp"

Island::Island(): Land() {}

Island::~Island() {}

std::string Island::get_full_type() const
{
	return Land::get_full_type() + " - Island";
}

Card::Color Island::get_color() const
{
	return Color::Blue;
}

std::string Island::get_name() const
{
	return "Island";
}

std::string Island::get_description() const
{
	return "";
}

Card* Island::clone() const
{
	return new Island(*this);
}
