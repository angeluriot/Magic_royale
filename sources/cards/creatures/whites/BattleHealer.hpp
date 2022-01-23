#ifndef BATTLEHEALER_HPP
#define BATTLEHEALER_HPP

#include "cards/Creature.hpp"

class BattleHealer : public Creature
{
public:

	BattleHealer();
	BattleHealer(const BattleHealer& other) = default;
	~BattleHealer();

	BattleHealer& operator=(const BattleHealer& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::vector<Capacity> get_capacities() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	int get_full_power() const override;
	int get_full_toughness() const override;
	void spawn() override;
	void special_ability() override;
	Card* clone() const override;
};

#endif
