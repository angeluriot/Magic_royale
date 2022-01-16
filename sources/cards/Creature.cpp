#include <iostream>
#include <string>
#include <algorithm>
#include "cards/Creature.hpp"
#include "Game.hpp"
#include "renderer/print.hpp"

Creature::Creature(int full_power, int full_toughness): Card(), m_power(full_power), m_toughness(full_toughness),
	m_can_attack(false), m_attacking(false), m_blocking(false), m_shield(false), m_alive(true)
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

Creature::~Creature() {}

bool Creature::is_alive()
{
	return m_alive;
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
		m_alive = false;
}

void Creature::remove_target(const Creature& target)
{
	for (auto it = m_targets.begin(); it != m_targets.end(); ++it)
		if (*it == &target)
			m_targets.erase(it);
}

void Creature::spawn() {}

void Creature::special_ability() {}

bool Creature::is_blockable() const
{
	auto capacities = get_capacities();
	return !(std::find(capacities.begin(), capacities.end(), Capacity::Unblockable) != capacities.end());
}

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

bool Creature::is_blocking() const
{
	return m_blocking;
}

void Creature::will_attack()
{
	m_attacking = true;
}

void Creature::will_not_attack()
{
	m_attacking = false;
}

void Creature::change_order()
{
	int new_order;
	std::vector<Creature*> new_targets;
	std::cout << "Entrez le nouvel ordre d'attaque de cette creature :" << std::endl;;

	for (size_t i = 0; i < m_targets.size(); i++)
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
	m_blocking = true;
	card.m_targets.push_back(this);
}

void Creature::will_not_block()
{
	m_blocking = false;
	m_owner->get_opponent().remove_target(*this);
}

void Creature::attack()
{
	if (!m_targets.empty())
	{
		for (Creature* target : m_targets)
		{
			target->reduce_toughness(m_power);
			target->block(*this);

			if (!m_alive)
				break;
		}
	}

	for (auto& target : m_targets)
		target->m_blocking = false;

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
	std::cout << bold << "Power/Toughness: " << ::reset << ::get_color(get_color()) << get_full_power() + " / " + get_full_toughness() << End(1);
	std::cout << bold << "Description: " << ::reset << ::get_color(get_color()) << get_description() << End(1);
}

void Creature::die() {}
