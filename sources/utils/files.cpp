#include "utils/files.hpp"
#include "renderer/print.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include "utils/utils.hpp"

std::vector<std::string> get_files_in_directory(const std::string& directory)
{
	namespace fs = std::filesystem;
	std::vector<std::string> files;

	for (const auto& entry : fs::directory_iterator(directory))
		files.push_back(entry.path().string());

	return files;
}

std::vector<std::string> get_decks_name()
{
	auto decks = get_files_in_directory("decks");

	for (auto& deck : decks)
	{
		deck.erase(deck.begin(), deck.begin() + 6); // Erases "decks/" from the deck's name
		deck.erase(deck.begin() + deck.find_first_of('.'), deck.end()); // Erases ".txt" from the deck's name
	}

	return decks;
}

std::vector<std::string> get_cards_from_deck(const std::string& deck_file)
{
	std::string deck_path = "decks/" + deck_file + ".txt";
	std::string line;
	std::ifstream deck(deck_path);
	std::vector<std::string> cards;

	if (deck.is_open())
	{
		while (getline(deck, line))
			cards.push_back(remove_spaces(line));

		deck.close();
	}

	else
		throw_error("Unable to open \"" + to_str(italic) + deck_file + to_str(no_italic) + "\".");

	return cards;
}
