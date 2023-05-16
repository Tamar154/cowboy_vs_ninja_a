#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : private Team
    {

    public:
        // ~SmartTeam() override;

        /**
         * Overrides the print function of Team
         */
        void print();
    };
}