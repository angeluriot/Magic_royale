#include <iostream>
#include <string>
#include "cards/Creature.hpp"
#include "Game.hpp"
#include "renderer/Renderer.hpp"

Creature::Creature(): Card(), m_power(get_full_power()), m_toughness(get_full_toughness()), m_can_attack(false),
	m_attacking(false), m_alive(true), m_shield(false)
{
	auto capacities = get_capacities();

	for (auto& capacity : capacities)
	{
		if (capacity == Capacity::Shield)
			m_shield = true;

		else if (capacity == Capacity::Haste)
			m_can_attack = true;
	}
}

Card::Type Creature::get_type() const
{
	return Type::Creature;
}

std::string Creature::get_full_type() const
{
	return "Creature";
}

std::vector<Creature::Capacity> Creature::get_capacities() const
{
	return {};
}

int Creature::get_full_power() const
{
	return 0;
}

int Creature::get_full_toughness() const
{
	return 0;
}

int Creature::get_power() const
{
	return m_power;
}

int Creature::get_toughness() const
{
	return m_toughness;
}

void Creature::reduce_toughness(int amount)
{
	m_toughness -= amount;

	if (m_toughness <= 0)
		die();
}

void Creature::spawn() {}

void Creature::special_ability() {}

bool Creature::can_attack() const
{
	return m_can_attack;
}

void Creature::allow_attack()
{
	m_can_attack = true;
}

bool Creature::is_attacking() const
{
	return m_attacking;
}

void Creature::will_attack()
{
	m_attacking = true;
}

void Creature::change_order()
{
	int new_order;
	std::vector<Creature*> new_targets;
	std::cout << "Entrez le nouvel ordre d'attaque de cette creature :" << std::endl;;

	for (int i = 0; i < m_targets.size(); i++)
	{
		std::cin >> new_order;
		new_order--;
		new_targets.push_back(m_targets.at(new_order));
	}

	m_targets.clear();

	for (Creature* target : new_targets)
	{
		m_targets.push_back(target);
		std::cout << target->get_name() << std::endl;
	}
}

void Creature::will_block(Creature& card)
{
	card.m_targets.push_back(this);
}

void Creature::attack()
{
	if (m_targets.empty())
		Game::players[1 - Game::turn].reduce_health(m_power);

	else
		for (Creature* target : m_targets)
		{
			target->reduce_toughness(m_power);
			target->block(*this);

			if (!m_alive)
				break;
		}

	m_targets.clear();
	m_attacking = false;
}

void Creature::block(Creature& card)
{
	card.reduce_toughness(get_power());
}

void Creature::reset()
{
	Card::reset();
	m_power = get_full_power();
	m_toughness = get_full_toughness();
	allow_attack();
}

void Creature::print() const
{
	Card::print();

	Renderer::print("Power/Toughness: ", Renderer::Color::White, true);
	Renderer::print(std::to_string(get_full_power()) + " / " + std::to_string(get_full_toughness()), Renderer::get_color(get_color()));
	Renderer::new_lines();
}

void Creature::die()
{
	m_alive = false;
}