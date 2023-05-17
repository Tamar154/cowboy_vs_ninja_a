#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leader) : _leader(leader)
    {
        _team.push_back(_leader);
    }

    Team::~Team()
    {
        for (Character *c : _team)
        {
            delete c;
        }
        // delete _leader;
    }

    std::vector<Character *> Team::getTeam()
    {
        return _team;
    }

    Character *Team::getLeader()
    {
        return _leader;
    }

    void Team::add(Character *player)
    {
        if (_team.size() < TEAM_SIZE)
        {
            _team.push_back(player);
        }
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