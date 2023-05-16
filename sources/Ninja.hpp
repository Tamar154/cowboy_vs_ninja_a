#pragma once

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character // public?
    {
    private:
        int _speed;

    public:
        Ninja(const std::string &name, const Point &location);

        int getSpeed();
        void setSpeed(int speed);

        void move(Character *enemy);
        void slash(Character *enemy);
    };

}