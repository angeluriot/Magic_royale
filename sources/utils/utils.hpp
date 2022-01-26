#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include "cards/Card.hpp"
#include "renderer/print.hpp"

/**
 * @brief Remove spaces in the beginning and end of a string.
 *
 * @param str the input string
 * @return the string without spaces
 */
std::string remove_spaces(const std::string& str);

/**
 * @brief Convert string view to string.
 *
 * @param str the input string view
 * @return the output string
 */
inline std::string to_str(const std::string_view& str)
{
	return std::string(str.data(), str.size());
}

/**
 * @brief Convert Card types to string.
 *
 * @param type the card type
 * @return the resulting string
 */
inline std::string to_str(Card::Type type)
{
	switch (type)
	{
	case Card::Type::Creature:
		return "C";
	case Card::Type::Land:
		return "L";
	case Card::Type::Spell:
		return "S";
	default:
		return "";
	}
}

/**
 * @brief Convert objects to string.
 *
 * @tparam T the object type
 * @param object the object to convert
 * @return the resulting string
 */
template <typename T>
inline std::string to_str(const T& object)
{
	return std::to_string(object);
}

/**
 * @brief Return a random int between two values.
 *
 * @param min the min value
 * @param max the max value
 * @return the random int
 */
inline int random_int(int min, int max)
{
	return min + (rand() % (max - min));
}

/**
 * @brief Quit the program after asking.
 */
inline void quit_game()
{
	std::cout << red << "Do you really want to leave the game?" << End(1);

	if (choice({ "No, I want to keep playing", "Yes, I want to leave" }, { green, red }) == 1)
	{
		std::cout << bold << yellow << "Bye!" << End(1);
		exit(EXIT_SUCCESS);
	}
}

#endif
