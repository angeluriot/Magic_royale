#include <iostream>
#include "cards/lands/land.hpp"

Land::Land(std::string name, enum type land_type): Card(name), m_land_type(land_type)
{
    std::cout << "Construction de land : " << this << std::endl;
}

Land::~Land()
{
    std::cout << "Destruction de land : " << this << std::endl;
}
