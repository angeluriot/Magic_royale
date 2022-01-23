#ifndef BATTLERAM_HPP
#define BATTLERAM_HPP

#include "cards/Creature.hpp"

class BattleRam : public Creature
{
public:

	BattleRam();
	BattleRam(const BattleRam& other) = default;
	~BattleRam();

	BattleRam& operator=(const BattleRam& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::vector<Capacity> get_capacities() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
	void die() override;
	Card* clone() const override;
};

#endif
