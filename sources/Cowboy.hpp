#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character // public?
    {
    private:
        int _numOfBullets;

    public:
        Cowboy(const std::string &name, const Point &location);

        int getNumOfBullets();

        void setNumOfBullets(int numOfBullets);

        void shoot(Character *enemy);
        bool hasBullets();
        void reload();
    };

}