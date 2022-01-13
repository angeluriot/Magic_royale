#include "cards/lands/Forest.hpp"

Forest::Forest(): Land() {}

Forest::~Forest() {}

std::string Forest::get_full_type() const
{
	return Land::get_full_type() + " - Forest";
}

Card::Color Forest::get_color() const
{
	return Color::Green;
}

std::string Forest::get_name() const
{
	return "Forest";
}

std::string Forest::get_description() const
{
	return "";
}

Card* Forest::clone() const
{
	return new Forest(*this);
}
