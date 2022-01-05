#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "cards/Card.hpp"
#include <string>

class Creature : public Card
{
protected:

    std::string m_type;
    int m_cost[5];
    int m_strength;
    int m_stamina;
    bool m_can_attack;

public:

    Creature(std::string name, std::string type, int cost[5], int strength, int stamina);
    ~Creature();
    void attack();
    void block();

};

#endif
