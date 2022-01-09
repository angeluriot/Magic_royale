#include "utils/print.hpp"

std::string bold_tag = "\033[1m";

std::string get_color(Color color)
{
	switch (color)
	{
	case Color::red:
		return "\033[31m";
	case Color::green:
		return "\033[32m";
	case Color::yellow:
		return "\033[33m";
	case Color::blue:
		return "\033[34m";
	case Color::magenta:
		return "\033[35m";
	case Color::cyan:
		return "\033[36m";
	case Color::white:
		return "\033[37m";
	default:
		return "";
	}
}

void print(std::string text, Color color, bool bold, bool confirm)
{
	std::cout << get_color(color) << (bold ? bold_tag : "") << text << "\033[0m" << std::endl;

	if (confirm)
	{
		new_line();
		std::cin.get();
	}
}

void new_line()
{
	std::cout << std::endl;
}

void confirm()
{
	new_line();
	std::cin.get();
}
