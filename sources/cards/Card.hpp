#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Card
{
protected:

    std::string m_name;
    bool m_engaged;

public:

	Card();
	Card(std::string name);
	~Card();
    void engage();
    void disengage();
    bool is_engaged();

};

#endif
