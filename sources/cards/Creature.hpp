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
		Flying,			// Fly
		Reach,			// Can reach flying creatures
		FirstStrike,	// Attack first
		Haste,			// Play on first turn
		Unblockable,	// Can't be blocked
		ZoneDamage,		// Damages go to all blockers
		MultiHit,		// Attack blockers and the player
		Freeze,			// Low the blocker's dammages
		Kamikaze,		// Die on attack
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
	std::vector<Creature*> m_targets;

public:

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
	virtual void reduce_toughness(int amount);
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
	virtual void attack();
	virtual void attack(Creature& creature);
	virtual void block(Creature& creature);
	virtual void reset() override;
	virtual void print() const override;
	virtual void die();
};

#endif
