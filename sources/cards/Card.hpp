#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Card
{
protected:
    
    std::string m_name;
    bool m_is_engaged;

public:

	Card(std::string name);
	~Card();
    void engage();
    void disengage();
    bool get_is_engaged();

};

#endif
