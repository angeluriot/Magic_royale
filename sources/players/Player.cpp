#include "players/Player.hpp"

Player::Player()
{
	m_health = 20;
}

Player::~Player()
{
	
}

std::string Player::get_name() const
{
	return m_name;
}

void Player::set_name(const std::string& name)
{
	m_name = name;
}
