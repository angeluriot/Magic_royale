#include "utils/print.hpp"

std::string bold_tag = "\033[1m";

std::string get_color(std::string color)
{
	if (color == "red")
		return "\033[1;31m";
	else if (color == "green")
		return "\033[1;32m";
	else if (color == "yellow")
		return "\033[1;33m";
	else if (color == "blue")
		return "\033[1;34m";
	else if (color == "magenta")
		return "\033[1;35m";
	else if (color == "cyan")
		return "\033[1;36m";
	else if (color == "white")
		return "\033[1;37m";
	else
		return "\033[0m";
}

void print(std::string text, std::string color, bool bold, bool confirm)
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
