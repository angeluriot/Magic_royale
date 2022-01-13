#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "cards/Card.hpp"

constexpr std::string_view black = "\033[30m";
constexpr std::string_view red = "\033[31m";
constexpr std::string_view green = "\033[32m";
constexpr std::string_view yellow = "\033[33m";
constexpr std::string_view blue = "\033[34m";
constexpr std::string_view magenta = "\033[35m";
constexpr std::string_view cyan = "\033[36m";
constexpr std::string_view white = "\033[97m";
constexpr std::string_view gray = "\033[90m";
constexpr std::string_view colorless = "\033[37m";
constexpr std::string_view reset = "\033[0m";
constexpr std::string_view bold = "\033[1m";
constexpr std::string_view italic = "\033[3m";
constexpr std::string_view underline = "\033[4m";
constexpr std::string_view blink = "\033[5m";
constexpr std::string_view reverse = "\033[7m";
constexpr std::string_view no_underline = "\033[24m";
constexpr std::string_view no_blink = "\033[25m";
constexpr std::string_view no_reverse = "\033[27m";
constexpr std::string_view no_italic = "\033[23m";
constexpr std::string_view no_bold = "\033[22m";

class End
{
private:

	int nb_new_lines;

public:

	End(int nb_new_lines = 0);
	friend std::ostream& operator<<(std::ostream& os, const End& end);
};

std::string input(std::string prompt, bool same_line = true);
int choice(std::vector<std::string> choices, int initial_choice = 0);
std::string_view get_color(Card::Color color);
void confirm();
void clear_console();

#endif
