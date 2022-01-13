#include "Game.hpp"
#include "renderer/Renderer.hpp"

std::array<Player, 2> Game::players;
int Game::turn = 0;

void Game::start()
{
	Renderer::clear();
	Renderer::print("                    _                               _\n"
		"  /\\/\\   __ _  __ _(_) ___    _ __ ___  _   _  __ _| | ___\n"
		" /    \\ / _` |/ _` | |/ __|  | '__/ _ \\| | | |/ _` | |/ _ \\\n"
		"/ /\\/\\ \\ (_| | (_| | | (__   | | | (_) | |_| | (_| | |  __/\n"
		"\\/    \\/\\__,_|\\__, |_|\\___|  |_|  \\___/ \\__, |\\__,_|_|\\___|\n"
		"              |___/                     |___/\n", Renderer::Color::Yellow, true);
	Renderer::new_lines(2);
	Renderer::print("---=([  Welcome to Magic Royale!  ])=---", Renderer::Color::Yellow, true);
	Renderer::new_lines();
}

void Game::create_decks()
{
	
}

void Game::play()
{
	
}
