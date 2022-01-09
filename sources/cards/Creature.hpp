#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "cards/Card.hpp"
#include <string>
#include <vector>

class Creature : public Card
{
protected:

	int m_power;
	int m_toughness;
	bool m_can_attack;
	bool m_attacking;
	bool alive;
	std::vector<Creature*> m_targets;

public:

	Creature(int full_power, int full_toughness);
	Creature(const Creature& other) = default;

	Creature& operator=(const Creature& other) = default;

	virtual Type get_type() const override;
	virtual std::string get_full_type() const override;
	virtual int get_full_power() const = 0;
	virtual int get_full_toughness() const = 0;
	virtual int get_power() const;
	virtual int get_toughness() const;
	virtual void reduce_toughness(int amount);
	virtual bool can_attack() const;
	virtual void allow_attack();
	virtual bool is_attacking() const;
	virtual void will_attack();
	virtual void change_order();
	virtual void block(Creature& card);
	virtual void attack();
	virtual void reset() override;
	virtual void print() const override;
};

#endif
