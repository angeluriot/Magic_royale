#include <iostream>
#include <string>
#include "cards/creatures/Creature.hpp"

Creature::Creature(std::string name, std::string type, int cost[5], int strength, int stamina): Card(name), m_type(type), m_cost(cost), m_strength(strength), m_stamina(stamina), m_can_attack(false)
{
    std::cout << "Construction de creature : " << this << std::endl;
}

Creature::~Creature()
{
    std::cout << "Destruction de creature : " << this << std::endl;
}

void Creature::attack()
{

}

void Creature::block()
{

}
