#include <iostream>
#include <string>
#include "cards/Card.hpp"

Card::Card()
{

}

Card::Card(std::string name): m_name(name), m_engaged(false)
{
    std::cout << "Construction de card : " << this << std::endl;
}

Card::~Card()
{
    std::cout << "Destruction de card : " << this << std::endl;
}

void Card::engage()
{
    m_engaged = true;
}

void Card::disengage()
{
    m_engaged = false;
}

bool Card::is_engaged()
{
    return m_engaged;
}
