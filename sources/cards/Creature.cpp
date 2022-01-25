#include <iostream>
#include <string>
#include <algorithm>
#include "cards/Creature.hpp"
#include "Game.hpp"
#include "renderer/print.hpp"
#include "utils/utils.hpp"

Creature::Creature(int full_power, int full_toughness, const std::vector<Creature::Capacity>& capacities): Card(),
	m_power(full_power), m_toughness(full_toughness), m_can_attack(false), m_attacking(false), m_blocking(false), m_shield(false), m_alive(true), m_clone(false)
{
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

std::string Creature::get_description() const
{
	auto capacities = get_capacities();
	std::string description = "";

	for (auto& capacity : capacities)
	{
		if (capacity == Capacity::Flying)
			description += "- " + to_str(underline) + "Flying:" + to_str(no_underline) + " Only creatures whith " + to_str(italic) + "Reach" + to_str(no_italic) + " can attack it.\n";

		if (capacity == Capacity::Reach)
			description += "- " + to_str(underline) + "Reach:" + to_str(no_underline) + " Can attack " + to_str(italic) + "Flying" + to_str(no_italic) + " creatures.\n";

		if (capacity == Capacity::FirstStrike)
			description += "- " + to_str(underline) + "First Strike:" + to_str(no_underline) + " Attack first.\n";

		if (capacity == Capacity::Haste)
			description += "- " + to_str(underline) + "Haste:" + to_str(no_underline) + " Can attack on first turn.\n";

		if (capacity == Capacity::Unblockable)
			description += "- " + to_str(underline) + "Unblockable:" + to_str(no_underline) + " Cannot be blocked and cannot attack while blocking.\n";

		if (capacity == Capacity::ZoneDamage)
			description += "- " + to_str(underline) + "Zone Damage:" + to_str(no_underline) + " Damages go to all blockers.\n";

		if (capacity == Capacity::MultiHit)
			description += "- " + to_str(underline) + "Multi Hit:" + to_str(no_underline) + " Attack both blockers and the player.\n";

		if (capacity == Capacity::Freeze)
			description += "- " + to_str(underline) + "Freeze:" + to_str(no_underline) + " Low the blocker's dammages.\n";

		if (capacity == Capacity::Kamikaze)
			description += "- " + to_str(underline) + "Kamikaze:" + to_str(no_underline) + " Die on attack.\n";

		if (capacity == Capacity::Shield)
			description += "- " + to_str(underline) + "Shield:" + to_str(no_underline) + " The shield takes the first hit.\n";
	}

	return (description == "" ? "" : "\n" + description);
}

int Creature::get_power() const
{
	return m_power;
}

int Creature::get_toughness() const
{
	return m_toughness;
}

void Creature::modify_power(int amount)
{
	m_power += amount;

	if (m_power < 0)
		m_power = 0;
}

void Creature::modify_toughness(int amount)
{
	m_toughness += amount;

	if (m_toughness <= 0)
	{
		m_alive = false;
		m_toughness = 0;
	}
}

bool Creature::has_shield() const
{
	return m_shield;
}

void Creature::break_shield()
{
	m_shield = false;
}

void Creature::remove_target(const Creature& target)
{
	for (auto it = targets.begin(); it != targets.end();)
	{
		if (*it == &target)
			it = targets.erase(it);
		else
			++it;
	}
}

void Creature::spawn() {}

void Creature::special_ability() {}

bool Creature::has(Capacity capacity) const
{
	auto capacities = get_capacities();
	return std::find(capacities.begin(), capacities.end(), capacity) != capacities.end();
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

	for (size_t i = 0; i < targets.size(); i++)
	{
		std::cin >> new_order;
		new_order--;
		new_targets.push_back(targets[new_order]);
	}

	targets.clear();

	for (Creature* target : new_targets)
	{
		targets.push_back(target);
		std::cout << target->get_name() << std::endl;
	}
}

void Creature::will_block(Creature& creature)
{
	m_blocking = true;
	creature.targets.push_back(this);
}

void Creature::will_not_block()
{
	m_blocking = false;
	m_owner->get_opponent().remove_target(*this);
}

void Creature::apply_attack()
{
	bool has_attacked = false;

	if (targets.empty())
	{
		attack(get_power());
		has_attacked = true;
	}

	else
	{
		int power_left = get_power();

		for (Creature* target : targets)
		{
			if (has(Capacity::FirstStrike) && !target->has(Capacity::FirstStrike))
			{
				power_left = attack(*target, power_left);
				target->modify_power(has(Capacity::Freeze) ? -1 : 0);
				has_attacked = true;

				if (target->is_alive())
				{
					target->block(*this);
					modify_power(target->has(Capacity::Freeze) ? -1 : 0);
				}
			}

			else if (target->has(Capacity::FirstStrike) && !has(Capacity::FirstStrike))
			{
				target->block(*this);
				modify_power(target->has(Capacity::Freeze) ? -1 : 0);

				if (m_alive)
				{
					power_left = attack(*target, power_left);
					target->modify_power(has(Capacity::Freeze) ? -1 : 0);
					has_attacked = true;
				}
			}

			else
			{
				modify_power(target->has(Capacity::Freeze) ? -1 : 0);
				target->modify_power(has(Capacity::Freeze) ? -1 : 0);
				power_left = attack(*target, power_left);
				has_attacked = true;
				target->block(*this);
			}

			if (!m_alive)
				break;
		}

		if (has(Capacity::MultiHit))
		{
			attack(get_power());
			has_attacked = true;
		}

		else if (m_alive && power_left > 0)
		{
			attack(power_left);
			has_attacked = true;
		}
	}

	if (has(Capacity::Kamikaze) && has_attacked)
	{
		m_toughness = 0;
		m_alive = false;
	}
}

void Creature::attack(int power_left)
{
	m_owner->get_opponent().reduce_health(power_left);
}

int Creature::attack(Creature& creature, int power_left)
{
	if (power_left > 0)
	{
		if (creature.has(Capacity::Flying) && !has(Capacity::Reach))
			return power_left;

		if (creature.has_shield())
		{
			creature.break_shield();
			return power_left;
		}

		int damages = has(Capacity::ZoneDamage) ? get_power() : power_left;
		int result = std::max(damages - creature.get_toughness(), 0);

		if (damages >= creature.get_toughness())
			on_kill();

		creature.modify_toughness(-damages);
		return result;
	}

	return 0;
}

void Creature::block(Creature& creature)
{
	if (!has(Capacity::Unblockable))
	{
		if (creature.m_shield)
			creature.m_shield = false;

		else
		{
			if (get_power() >= creature.get_toughness())
				on_kill();

			creature.modify_toughness(-get_power());
		}

		if (has(Capacity::Kamikaze))
		{
			m_toughness = 0;
			m_alive = false;
		}
	}
}

void Creature::on_kill() {}

void Creature::reset()
{
	Card::reset();

	if (m_clone)
		m_toughness = 1;
	else
		m_toughness = get_full_toughness();

	m_power = get_full_power();
	m_can_attack = true;
	m_attacking = false;
	m_blocking = false;
	targets.clear();
}

void Creature::full_reset()
{
	Card::reset();
	m_power = get_full_power();
	m_toughness = get_full_toughness();
	m_can_attack = false;
	m_attacking = false;
	m_blocking = false;
	m_shield = false;
	m_alive = true;
	m_clone = false;
	targets.clear();

	if (has(Capacity::Shield))
		m_shield = true;

	if (has(Capacity::Haste))
		m_can_attack = true;
}

void Creature::set_clone()
{
	m_toughness = 1;
	m_clone = true;
}

void Creature::print() const
{
	Card::print();
	std::cout << bold << "Power/Toughness: " << ::reset << ::get_color(get_color()) << get_full_power() << " / " << get_full_toughness() << End(1);

	std::string description = get_description();

	if (description != "" && description.back() == '\n')
		description.pop_back();

	std::cout << bold << "Description: " << ::reset << ::get_color(get_color()) << description << End(1);
}

void Creature::die()
{
	std::cout << cyan << "[INFO] " << magenta << bold << m_owner->get_name() << ::reset << "'s " << ::reset << italic << ::get_color(get_color()) << get_name() << ::reset << " died." << End(2);
}
