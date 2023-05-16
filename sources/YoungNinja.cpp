
#include "YoungNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{

    YoungNinja::YoungNinja(std::string name, Point location)
        : Ninja(name, location)
    {
        Character::setHp(100);
        Ninja::setSpeed(14);
    }

}