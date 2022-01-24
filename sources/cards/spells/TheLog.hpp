#ifndef THELOG_HPP
#define THELOG_HPP

#include "cards/Spell.hpp"

class TheLog : public Spell
{
public:

	TheLog();
	TheLog(const TheLog& other) = default;
	~TheLog();

	TheLog& operator=(const TheLog& other) = default;

	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Cost get_cost() const override;
	void apply_effect() override;
	Card* clone() const override;
};

#endif
