#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "cards/Card.hpp"

constexpr std::string_view black = "\033[30m";			// Black.
constexpr std::string_view red = "\033[31m";			// Red.
constexpr std::string_view green = "\033[32m";			// Green.
constexpr std::string_view yellow = "\033[33m";			// Yellow.
constexpr std::string_view blue = "\033[34m";			// Blue.
constexpr std::string_view magenta = "\033[35m";		// Magenta.
constexpr std::string_view cyan = "\033[36m";			// Cyan.
constexpr std::string_view white = "\033[97m";			// White.
constexpr std::string_view gray = "\033[90m";			// Gray.
constexpr std::string_view colorless = "\033[37m";		// Colorless.
constexpr std::string_view reset = "\033[0m";			// Reset.
constexpr std::string_view bold = "\033[1m";			// Bold.
constexpr std::string_view italic = "\033[3m";			// Italic.
constexpr std::string_view underline = "\033[4m";		// Underline.
constexpr std::string_view blink = "\033[5m";			// Blink.
constexpr std::string_view reverse = "\033[7m";			// Reverse.
constexpr std::string_view no_underline = "\033[24m";	// No underline.
constexpr std::string_view no_blink = "\033[25m";		// No blink.
constexpr std::string_view no_reverse = "\033[27m";		// No reverse.
constexpr std::string_view no_italic = "\033[23m";		// No italic.
constexpr std::string_view no_bold = "\033[22m";		// No bold.

/**
 * @brief Struct to end prints.
 */
struct End
{
private:

	int nb_new_lines;	// The number of new lines.

public:

	/**
	 * @brief Construct a new End object
	 *
	 * @param nb_new_lines the number of new lines
	 */
	End(int nb_new_lines = 0);

	/**
	 * @brief Operator <<.
	 *
	 * @param os the intput stream
	 * @param end the End structure
	 * @return the output stream
	 */
	friend std::ostream& operator<<(std::ostream& os, const End& end);
};

/**
 * @brief Ask string to the user.
 *
 * @param prompt the question to ask.
 * @param same_line true if the question is on the same line as the prompt.
 * @return the response of the user.
 */
std::string input(const std::string& prompt, bool same_line = true);

/**
 * @brief Give a choice between several options to the user.
 *
 * @param choices the choices
 * @param additional additinal choices
 * @return the index of the choice
 */
int choice(const std::vector<std::string>& choices, const std::vector<std::string>& additional = {});

/**
 * @brief Give a choice between several options to the user.
 *
 * @param choices the choices
 * @param choice_colors the colors of the choices
 * @param additional additinal choices
 * @return the index of the choice
 */
int choice(const std::vector<std::string>& choices, const std::vector<std::string_view>& choice_colors, const std::vector<std::string>& additional = {});

/**
 * @brief Give the color string from a Card color.
 *
 * @param color the card color
 * @return the string color
 */
std::string_view get_color(Card::Color color);

/**
 * @brief Ask the user to confirm.
 */
void confirm();

/**
 * @brief Clear the console.
 */
void clear_console();

/**
 * @brief Trow an error.
 *
 * @param error the message of the error
 */
void throw_error(const std::string& error);

#endif
