#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leader) : _leader(leader) {}

    Team::~Team()
    {
        for (Character *c : _team)
        {
            delete c;
        }
        delete _leader;
    }

    void Team::add(Character *player)
    {
        _team.push_back(player);
    }

    void Team::attack(Team *enemy)
    {
    }

    int Team::stillAlive()
    {
        return 0;
    }

    void Team::print()
    {
    }
}