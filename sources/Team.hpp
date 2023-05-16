#pragma once

#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

#include <vector>

const int TEAM_SIZE = 10;

namespace ariel
{
    class Team
    {
    private:
        std::vector<Character *> _team;
        Character *_leader;

    public:
        Team(Character *leader);

        ~Team();

        Team(const Team &other) = delete;            // To make tidy happy
        Team &operator=(const Team &other) = delete; // To make tidy happy
        Team(Team &&other) = delete;                 // To make tidy happy
        Team &operator=(Team &&other) = delete;      // To make tidy happy

        void add(Character *player);

        void attack(Team *enemy);

        int stillAlive();

        void print();
    };
}