#include "players/Player.hpp"

Player::Player(): m_name(""), m_health(20), m_alive(true) {}

std::string Player::get_name() const
{
	return m_name;
}

void Player::set_name(const std::string& name)
{
	m_name = name;
}

int Player::get_health() const
{
	return m_health;
}

void Player::set_health(int health)
{
	m_health = health;
}

void Player::reduce_health(int amount)
{
	m_health -= amount;

	if (m_health <= 0)
		m_alive = false;
}

void Player::create_deck()
{
	// TODO
}

void Player::draw_card()
{
	// TODO
}

void Player::disengage_cards()
{
	// TODO
}

void Player::main_phase()
{
	// TODO
}

void Player::combat_phase()
{
	// TODO
}

void Player::secondary_phase()
{
	// TODO
}

void Player::play()
{
	// TODO
}
