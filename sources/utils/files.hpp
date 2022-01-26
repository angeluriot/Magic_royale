#ifndef FILES_HPP
#define FILES_HPP

#include <vector>
#include <string>

/**
 * @brief Get the files in a directory.
 *
 * @param directory the directory
 * @return the list of the files
 */
std::vector<std::string> get_files_in_directory(const std::string& directory);

/**
 * @brief Get the decks name
 *
 * @return the list of the decks name
 */
std::vector<std::string> get_decks_name();

/**
 * @brief Get the cards from deck
 *
 * @param file the deck
 * @return the list of the cards name
 */
std::vector<std::string> get_cards_from_deck(const std::string& file);

#endif
