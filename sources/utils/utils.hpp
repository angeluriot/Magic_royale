#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include "cards/Card.hpp"
#include "renderer/print.hpp"

std::string remove_spaces(const std::string& str);

inline std::string to_str(const std::string_view& str)
{
	return std::string(str.data(), str.size());
}

inline std::string to_str(Card::Type type)
{
	switch (type)
	{
	case Card::Type::Creature:
		return "C";
	case Card::Type::Land:
		return "L";
	default:
		return "";
	}
}

template <typename T>
inline std::string to_str(const T& object)
{
	return std::to_string(object);
}

inline int random_int(int min, int max)
{
	return min + (rand() % (max - min));
}

inline void quit_game()
{
	std::cout << red << "Do you really want to leave the game?" << End(1);

	if (choice({ "No I stay", "Yes I want to leave" }, { green, red }) == 1)
	{
		std::cout << bold << yellow << "Bye!" << End(1);
		exit(EXIT_SUCCESS);
	}
}

#endif
