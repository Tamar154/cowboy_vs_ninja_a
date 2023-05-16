
#include "TrainedNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{

    TrainedNinja::TrainedNinja(std::string name, Point location)
        : Ninja(name, location)
    {
        Character::setHp(120);
        Ninja::setSpeed(12);
    }

}