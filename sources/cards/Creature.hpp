#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "cards/Card.hpp"
#include <string>
#include <vector>

class Creature : public Card
{
public:

	enum class Capacity
	{
		Flying,			// Can't be blocked by creatures that don't have Reach
		Reach,			// Can reach flying creatures
		FirstStrike,	// Attacks first when blocking
		Haste,			// Can attack on first turn
		Unblockable,	// Can't be blocked
		ZoneDamage,		// Damages all blockers
		MultiHit,		// Attacks blockers and the player
		Freeze,			// Lowers the blocker's damage
		Kamikaze,		// Dies on attack
		Shield			// The shield takes the first hit
	};

protected:

	int m_power;
	int m_toughness;
	bool m_can_attack;
	bool m_attacking;
	bool m_blocking;
	bool m_shield;
	bool m_alive;
	bool m_clone;

public:

	std::vector<Creature*> m_targets;

	Creature(int full_power, int full_toughness, const std::vector<Creature::Capacity>& capacities);
	Creature(const Creature& other) = default;
	virtual ~Creature();

	Creature& operator=(const Creature& other) = default;

	bool is_alive();

	virtual Type get_type() const override;
	virtual std::string get_full_type() const override;
	virtual std::string get_description() const override;
	virtual std::vector<Capacity> get_capacities() const = 0;
	virtual int get_full_power() const = 0;
	virtual int get_full_toughness() const = 0;
	virtual int get_power() const;
	virtual int get_toughness() const;
	virtual void modify_power(int amount);
	virtual void modify_toughness(int amount);
	virtual bool has_shield() const;
	virtual void break_shield();
	virtual void remove_target(const Creature& target);
	virtual void spawn();
	virtual void special_ability();
	virtual bool has(Capacity capacity) const;
	virtual bool can_attack() const;
	virtual void allow_attack();
	virtual bool is_attacking() const;
	virtual bool is_blocking() const;
	virtual void will_attack();
	virtual void will_not_attack();
	virtual void change_order();
	virtual void will_block(Creature& creature);
	virtual void will_not_block();
	virtual void apply_attack();
	virtual void attack(int power_left);
	virtual int attack(Creature& creature, int power_left);
	virtual void block(Creature& creature);
	virtual void on_kill();
	virtual void reset() override;
	virtual void full_reset();
	virtual void set_clone();
	virtual void print() const override;
	virtual void die();
};

#endif
