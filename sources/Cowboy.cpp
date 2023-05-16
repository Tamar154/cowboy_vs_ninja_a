#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(const string &name, const Point &location)
        : Character(location, 110, name), _numOfBullets(6) {}

    int Cowboy::getNumOfBullets() { return _numOfBullets; }

    void Cowboy::setNumOfBullets(int numOfBullets) { _numOfBullets = numOfBullets; }

    void Cowboy::shoot(Character *enemy)
    {
    }

    bool Cowboy::hasBullets()
    {
        return false;
    }

    void Cowboy::reload()
    {
    }
}