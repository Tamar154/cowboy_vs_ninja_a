#include "Character.hpp"

namespace ariel
{

    Character::Character(const Point &location, int hitPoints, std::string name)
        : _location(location), _hp(hitPoints), _name(name) {}

    /**
     * Getters
     */
    Point Character::getLocation() { return _location; }
    int Character::getHp() { return _hp; }
    string Character::getName() { return _name; }

    /**
     * Setters
     */
    void Character::setLocation(Point location) { _location = location; }
    void Character::setHp(int hitPoints) { _hp = hitPoints; }
    void Character::setName(string name) { _name = name; }

    bool Character::isAlive()
    {
        return false;
    }

    double Character::distance(const Character *other)
    {
        return 0.0;
    }

    void Character::hit(int amount)
    {
    }

    string Character::print()
    {
        return "";
    }

}