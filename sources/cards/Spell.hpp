#ifndef SPELL_HPP
#define SPELL_HPP

#include "cards/Card.hpp"
#include <string>

/**
 * @brief A class that represent a spell.
 */
class Spell : public Card
{
public:

	Spell();
	Spell(const Spell& other) = default;
	virtual ~Spell();

	Spell& operator=(const Spell& other) = default;

	virtual Type get_type() const override;
	virtual std::string get_full_type() const override;

	/**
	 * @brief Apply an effect to the game.
	 */
	virtual void apply_effect() = 0;

	virtual void print() const;
};

#endif
