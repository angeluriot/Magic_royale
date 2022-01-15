#ifndef FILES_HPP
#define FILES_HPP

#include <vector>
#include <string>

std::vector<std::string> get_files_in_directory(const std::string& directory);
std::vector<std::string> get_decks_name();
std::vector<std::string> get_cards_from_deck(const std::string& file);

#endif
