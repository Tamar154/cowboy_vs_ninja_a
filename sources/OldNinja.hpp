#pragma once

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja // public?
    {
    
    public:
        OldNinja(std::string name, Point location);
    };

}