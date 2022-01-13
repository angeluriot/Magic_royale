#ifndef PLAIN_HPP
#define PLAIN_HPP

#include "cards/Land.hpp"

class Plain : public Land
{
public:

	Plain();
	Plain(const Plain& other) = default;
	~Plain();

	Plain& operator=(const Plain& other) = default;

	std::string get_full_type() const override;
	Color get_color() const override;
	std::string get_name() const override;
	std::string get_description() const override;
	Card* clone() const override;
};

#endif
