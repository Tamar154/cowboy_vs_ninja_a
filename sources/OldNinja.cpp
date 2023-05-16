
#include "OldNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{

    OldNinja::OldNinja(std::string name, Point location)
        : Ninja(name, location)
    {
        Character::setHp(150);
        Ninja::setSpeed(8);
    }

}