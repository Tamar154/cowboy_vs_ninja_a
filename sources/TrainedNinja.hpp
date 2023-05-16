#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja // public?
    {

    public:
        TrainedNinja(std::string name, Point location);
    };

}