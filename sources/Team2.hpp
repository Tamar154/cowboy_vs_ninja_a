#pragma once

#include "Team.hpp"

namespace ariel
{
    class Team2 : private Team
    {

    public:

        // ~Team2() override;

        /**
         * Overrides the print function of Team
         */
        void print();
    };
}