#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <string>

enum class Color
{
	red,
	green,
	yellow,
	blue,
	magenta,
	cyan,
	white
};

void print(std::string text, Color color = Color::white, bool bold = false, bool confirm = false);
void new_line();
void confirm();

#endif
