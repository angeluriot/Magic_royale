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
	bool m_shield;
	bool m_alive;
	std::vector<Creature*> m_targets;

public:

	Creature();
	Creature(const Creature& other) = default;

	Creature& operator=(const Creature& other) = default;

	virtual Type get_type() const override;
	virtual std::string get_full_type() const override;
	virtual std::vector<Capacity> get_capacities() const;
	virtual int get_full_power() const;
	virtual int get_full_toughness() const;
	virtual int get_power() const;
	virtual int get_toughness() const;
	virtual void reduce_toughness(int amount);
	virtual void spawn();
	virtual void special_ability();
	virtual bool can_attack() const;
	virtual void allow_attack();
	virtual bool is_attacking() const;
	virtual void will_attack();
	virtual void change_order();
	virtual void will_block(Creature& card);
	virtual void attack();
	virtual void block(Creature& card);
	virtual void reset() override;
	virtual void print() const override;
	virtual void die();
};

#endif