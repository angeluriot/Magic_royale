#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "cards/Card.hpp"
#include <string>
#include <vector>

/**
 * @brief A class that represent a creature.
 */
class Creature : public Card
{
public:

	/**
	 * @brief An enum that represent the creature capacity.
	 */
	enum class Capacity
	{
		Flying,			// Can't be blocked by creatures that don't have Reach.
		Reach,			// Can reach flying creatures.
		FirstStrike,	// Attacks first when blocking.
		Haste,			// Can attack on first turn.
		Unblockable,	// Cannot be blocked and cannot attack while blocking.
		ZoneDamage,		// Damages all blockers.
		MultiHit,		// Attacks blockers and the player.
		Freeze,			// Lowers the blocker's damage.
		Kamikaze,		// Dies on attack.
		Shield			// The shield takes the first hit.
	};

protected:

	int m_power;					// The creature power.
	int m_toughness;				// The creature toughness.
	bool m_can_attack;				// Ttrue if the creature can attack.
	bool m_attacking;				// True if the creature is attacking.
	bool m_blocking;				// True if the creature is blocking.
	bool m_shield;					// True if the creature has a shield.
	bool m_alive;					// True if the creature is alive.
	bool m_clone;					// True if the creature is a clone.

public:

	std::vector<Creature*> targets;	// The creatures targeted by the creature.

	/**
	 * @brief Construct a new Creature object.
	 *
	 * @param full_power the full power of the creature
	 * @param full_toughness the full toughness of the creature
	 * @param capacities the capacities of the creature
	 */
	Creature(int full_power, int full_toughness, const std::vector<Creature::Capacity>& capacities);

	Creature(const Creature& other) = default;
	virtual ~Creature();

	Creature& operator=(const Creature& other) = default;

	/**
	 * @brief Tell if the creature is alive.
	 *
	 * @return true if the creature is alive
	 */
	virtual bool is_alive();

	virtual Type get_type() const override;
	virtual std::string get_full_type() const override;
	virtual std::string get_description() const override;

	/**
	 * @brief Give the capacities of the creature.
	 *
	 * @return the capacities of the creature
	 */
	virtual std::vector<Capacity> get_capacities() const = 0;

	/**
	 * @brief Give the full power of the creature.
	 *
	 * @return the full power of the creature
	 */
	virtual int get_full_power() const = 0;

	/**
	 * @brief Give the full toughness of the creature.
	 *
	 * @return the full toughness of the creature
	 */
	virtual int get_full_toughness() const = 0;

	/**
	 * @brief Give the power of the creature.
	 *
	 * @return the power of the creature
	 */
	virtual int get_power() const;

	/**
	 * @brief Give the toughness of the creature.
	 *
	 * @return the toughness of the creature
	 */
	virtual int get_toughness() const;

	/**
	 * @brief Change the power of the creature.
	 *
	 * @param amount the change
	 */
	virtual void modify_power(int amount);

	/**
	 * @brief Change the toughness of the creature.
	 *
	 * @param amount the change
	 */
	virtual void modify_toughness(int amount);

	/**
	 * @brief Tell if the creature has a shield.
	 *
	 * @return true if the creature has a shield
	 */
	virtual bool has_shield() const;

	/**
	 * @brief Break the shield of the creature.
	 */
	virtual void break_shield();

	/**
	 * @brief Remove a target of a creature.
	 *
	 * @param target the target to remove
	 */
	virtual void remove_target(const Creature& target);

	/**
	 * @brief Spawn action of the creature.
	 */
	virtual void spawn();

	/**
	 * @brief Special action of the creature.
	 */
	virtual void special_ability();

	/**
	 * @brief Tell if the creature has a capacity.
	 *
	 * @param capacity the capacity to check
	 * @return true if the creature has the capacity
	 */
	virtual bool has(Capacity capacity) const;

	/**
	 * @brief Tell if the creature can attack.
	 *
	 * @return true if the creature can attack
	 */
	virtual bool can_attack() const;

	/**
	 * @brief Allow the attack for the creature.
	 */
	virtual void allow_attack();

	/**
	 * @brief Tell if the creature is attacking.
	 *
	 * @return true if the creature is attacking
	 */
	virtual bool is_attacking() const;

	/**
	 * @brief Tell if the creature is blocking.
	 *
	 * @return true if te creature is blocking
	 */
	virtual bool is_blocking() const;

	/**
	 * @brief Set that the creature will attack.
	 */
	virtual void will_attack();

	/**
	 * @brief Cancel the attack of the creature.
	 */
	virtual void will_not_attack();

	/**
	 * @brief Set that the creature will block.
	 */
	virtual void will_block(Creature& creature);

	/**
	 * @brief Cancel the blocking of the creature.
	 */
	virtual void will_not_block();

	/**
	 * @brief Apply the damages of an attack.
	 */
	virtual void apply_attack();

	/**
	 * @brief Attack the player.
	 *
	 * @param power_left the left power
	 */
	virtual void attack(int power_left);

	/**
	 * @brief Attack a creature.
	 *
	 * @param creature the creature to attack
	 * @param power_left the left power
	 * @return the left power
	 */
	virtual int attack(Creature& creature, int power_left);

	/**
	 * @brief Block a creature.
	 *
	 * @param creature the creature to block
	 */
	virtual void block(Creature& creature);

	/**
	 * @brief On kill action of the creature.
	 */
	virtual void on_kill();

	virtual void reset() override;

	/**
	 * @brief Reset entirely the creature.
	 */
	virtual void full_reset();

	/**
	 * @brief Set that the creature is a clone.
	 */
	virtual void set_clone();

	virtual void print() const override;

	/**
	 * @brief Action on death.
	 */
	virtual void die();
};

#endif
