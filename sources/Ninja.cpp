#include "Ninja.hpp"

namespace ariel
{

    Ninja::Ninja(const string &name, const Point &location)
        : Character(location, 0, name), _speed(0) {}

    /**
     * Getters and Setters
     */
    int Ninja::getSpeed() { return this->_speed; }

    void Ninja::setSpeed(int speed) { this->_speed = speed; }

    void Ninja::move(Character *enemy)
    {
    }
    void Ninja::slash(Character *enemy)
    {
    }

}