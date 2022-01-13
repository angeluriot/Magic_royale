#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <iostream>
#include <string>
#include "cards/Card.hpp"

class Renderer
{
public:

	enum class Color
	{
		Red,
		Green,
		Yellow,
		Blue,
		Magenta,
		Cyan,
		White,
		Gray
	};

	static Color get_color(Card::Color color);
	static void print(std::string text, Color color = Color::White, bool bold = false);
	static void new_lines(size_t number = 1);
	static void confirm();
	static void clear();
};

#endif
