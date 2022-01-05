#include <iostream>
#include <string>
#include "cards/Card.hpp"

Card::Card(std::string name): m_name(name), m_is_engaged(false)
{
    std::cout << "Construction de card : " << this << std::endl;
}

Card::~Card()
{
    std::cout << "Destruction de card : " << this << std::endl;
}

void Card::engage()
{
    m_is_engaged = true;
}

void Card::disengage()
{
    m_is_engaged = false;
}

bool Card::get_is_engaged()
{
    return m_is_engaged;
}
