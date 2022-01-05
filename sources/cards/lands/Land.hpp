#ifndef LAND_HPP
#define LAND_HPP

#include "cards/Card.hpp"
#include <string>

class Land : public Card
{
protected:

    

public:

    enum type {Plain, Island, Swamp, Mountain, Forest};
    enum type m_land_type;
    Land(std::string name, enum type land_type);
    ~Land();

};

#endif
