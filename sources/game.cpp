#include "Game.hpp"
#include "utils/print.hpp"

std::array<Player, 2> Game::m_players;

void Game::start()
{
	print("                    _        _   _              ___      _   _               _\n"
		"  /\\/\\   __ _  __ _(_) ___  | |_| |__   ___    / _ \\__ _| |_| |__   ___ _ __(_)_ __   __ _\n"
		" /    \\ / _` |/ _` | |/ __| | __| '_ \\ / _ \\  / /_\\/ _` | __| '_ \\ / _ \\ '__| | '_ \\ / _` |\n"
		"/ /\\/\\ \\ (_| | (_| | | (__  | |_| | | |  __/ / /_\\\\ (_| | |_| | | |  __/ |  | | | | | (_| |\n"
		"\\/    \\/\\__,_|\\__, |_|\\___|  \\__|_| |_|\\___| \\____/\\__,_|\\__|_| |_|\\___|_|  |_|_| |_|\\__, |\n"
		"              |___/                                                                  |___/\n", Color::yellow, true);

	print("---=([  Welcome to Magic the Gathering clone!  ])=---", Color::yellow, true, true);

}

void Game::create_decks()
{
	
}

void Game::play()
{
	
}
