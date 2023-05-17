#include "doctest.h"
#include "sources/Team.hpp"
#include <sstream>

using namespace ariel;

TEST_SUITE("POINT CLASS")
{
    Point p1(-2.0, 1.0);
    Point p2(3.0, 4.0);

    TEST_CASE("Constructor")
    {
        CHECK(p1.getX() == -2.0);
        CHECK(p1.getY() == 1.0);
    }

    TEST_CASE("Distance function")
    {

        CHECK(std::abs(p1.distance(p2) - p2.distance(p1)) < EPSILON);
    }

    TEST_CASE("moveTowards function - destination is whithin the distance")
    {
        // if the allowed distance is greater than distance between originPoint and destinationPoint
        CHECK_EQ(Point::moveTowards(p1, p2, 10.0), p2);
    }

    TEST_CASE("moveTowards function - estination is not whithin the distance")
    {
        Point origin(0.0, 0.0);
        Point dest(4.0, 0.0);
        CHECK_EQ(Point::moveTowards(origin, dest, 3.0), Point(3.0, 0.0));
    }
}

TEST_SUITE("CHARACTER CLASS")
{

    TEST_CASE("Constructor")
    {
        Point location(-2.0, 1.0);
        Character c1(location, 100, "Alice");

        CHECK_EQ(c1.getName(), "Alice");
        CHECK_EQ(c1.getLocation(), location);
        CHECK_EQ(c1.getHp(), 100);
    }

    TEST_CASE("isAlive function")
    {
        Point location(-2.0, 1.0);
        Character c1(location, 100, "Alice");

        CHECK_EQ(c1.isAlive(), true);
        c1.setHp(0);
        CHECK_EQ(c1.isAlive(), false);
    }

    TEST_CASE("distance function")
    {
        Point location1(-2.0, 1.0);
        Point location2(3.0, 4.0);
        Character c1(location1, 100, "Alice");
        Character c2(location2, 100, "Bob");
        CHECK_EQ(c1.distance(&c2), location1.distance(location2));

        // one of them is dead
        c2.setHp(0);
        CHECK_THROWS(c1.distance(&c2));
    }

    TEST_CASE("hit function")
    {
        Point location1(-2.0, 1.0);
        Character c1(location1, 100, "Alice");

        c1.hit(0);
        CHECK_EQ(c1.getHp(), 100);

        c1.hit(20);
        CHECK_EQ(c1.getHp(), 80);

        CHECK_THROWS(c1.hit(-2));
    }
}

TEST_SUITE("COWBOY CLASS")
{
    TEST_CASE("Constructor")
    {
        Point location1(3.0, 4.0);
        Cowboy cowboy1("Bob", location1);

        CHECK_EQ(cowboy1.getName(), "Bob");
        CHECK_EQ(cowboy1.getLocation(), location1);
        CHECK_EQ(cowboy1.getHp(), 110);
        CHECK_EQ(cowboy1.getNumOfBullets(), 6);
    }

    TEST_CASE("Shoot + hasBullets functions")
    {
        Point location1(3.0, 4.0);
        Point location2(-2.0, 1.0);
        Cowboy cowboy1("Bob", location1);
        Cowboy enemy("Alice", location2);

        cowboy1.shoot(&enemy);

        CHECK_EQ(enemy.getHp(), 100);
        CHECK_EQ(cowboy1.getNumOfBullets(), 5);
        CHECK_EQ(cowboy1.hasBullets(), true);

        // Shooter has no bullets
        cowboy1.setNumOfBullets(0);
        cowboy1.shoot(&enemy);

        CHECK_EQ(enemy.getHp(), 100);
        CHECK_EQ(cowboy1.getNumOfBullets(), 0);
        CHECK_EQ(cowboy1.hasBullets(), false);

        // Shooter is dead
        cowboy1.setHp(0);
        cowboy1.shoot(&enemy);

        CHECK_EQ(enemy.getHp(), 100);
    }

    TEST_CASE("reload functions")
    {
        Point location1(3.0, 4.0);
        Cowboy cowboy1("Bob", location1);
        cowboy1.setNumOfBullets(2);
        cowboy1.reload();

        CHECK_EQ(cowboy1.getNumOfBullets(), 6);

        // Can't reload when dead
        cowboy1.setHp(0);
        CHECK_THROWS(cowboy1.reload());
    }
}

TEST_SUITE("NINJA CLASS")
{
    TEST_CASE("CONSTRUCTORS")
    {
        SUBCASE("YoungNinja")
        {
            Point location1(3.0, 4.0);
            YoungNinja youngninja1("Bob", location1);

            CHECK_EQ(youngninja1.getLocation(), location1);
            CHECK_EQ(youngninja1.getName(), "Bob");
            CHECK_EQ(youngninja1.getHp(), 100);
            CHECK_EQ(youngninja1.getSpeed(), 14);
        }
        SUBCASE("TrainedNinja")
        {
            Point location1(3.0, 4.0);
            TrainedNinja trainedninja1("Bob", location1);

            CHECK_EQ(trainedninja1.getLocation(), location1);
            CHECK_EQ(trainedninja1.getName(), "Bob");
            CHECK_EQ(trainedninja1.getHp(), 120);
            CHECK_EQ(trainedninja1.getSpeed(), 12);
        }
        SUBCASE("OldNinja")
        {
            Point location1(3.0, 4.0);
            OldNinja oldninja1("Bob", location1);

            CHECK_EQ(oldninja1.getLocation(), location1);
            CHECK_EQ(oldninja1.getName(), "Bob");
            CHECK_EQ(oldninja1.getHp(), 150);
            CHECK_EQ(oldninja1.getSpeed(), 8);
        }
    }

    TEST_CASE("move function")
    {
        Point enemy_location(1.5, 0.0);
        Cowboy enemy("Alice", enemy_location);

        SUBCASE("YoungNinja")
        {
            Point young_location(1.0, 0.0);
            YoungNinja young_ninja("youngBob", young_location);

            young_ninja.move(&enemy);
            Point moved = Point::moveTowards(young_location, enemy_location, young_ninja.getSpeed());
            CHECK_EQ(young_ninja.getLocation(), moved);
        }
        SUBCASE("TrainedNinja")
        {
            Point trained_location(2.0, 0.0);
            TrainedNinja trained_ninja("trainedBob", trained_location);

            trained_ninja.move(&enemy);
            Point moved = Point::moveTowards(trained_location, enemy_location, trained_ninja.getSpeed());
            CHECK_EQ(trained_ninja.getLocation(), moved);
        }
        SUBCASE("OldNinja")
        {
            Point old_location(3.0, 0.0);
            OldNinja old_ninja("oldBob", old_location);

            old_ninja.move(&enemy);
            Point moved = Point::moveTowards(old_location, enemy_location, old_ninja.getSpeed());
            CHECK_EQ(old_ninja.getLocation(), moved);
        }
    }

    TEST_CASE("slash function")
    {
        SUBCASE("YoungNinja")
        {
            Point young_location(1.0, 0.0);
            YoungNinja young_ninja("youngBob", young_location);

            Point enemy_location(1.5, 0.0);
            Cowboy enemy("Alice", enemy_location);

            young_ninja.slash(&enemy);
            CHECK_EQ(enemy.getHp(), 70);

            // If ninja is dead, no damage is done
            young_ninja.setHp(0);
            young_ninja.slash(&enemy);
            CHECK_EQ(enemy.getHp(), 70);
        }

        SUBCASE("TrainedNinja")
        {
            Point trained_location(2.0, 0.0);
            TrainedNinja trained_ninja("trainedBob", trained_location);

            Point enemy_location(1.5, 0.0);
            Cowboy enemy("Alice", enemy_location);

            enemy.setHp(20);
            trained_ninja.slash(&enemy);
            CHECK_EQ(enemy.getHp(), 0);
        }
        SUBCASE("OldNinja")
        {
            Point old_location(3.0, 0.0);
            OldNinja old_ninja("oldBob", old_location);

            Point enemy_location(1.5, 0.0);
            Cowboy enemy("Alice", enemy_location);

            old_ninja.slash(&enemy);
            CHECK_EQ(enemy.getHp(), 110);
        }
    }
}

TEST_SUITE("TEAM CLASS")
{
    Point leader_location(0.0, 0.0);
    Cowboy *leader = new Cowboy("Bob", leader_location);
    Team team_A(leader);

    TEST_CASE("Constructor")
    {
        CHECK_EQ(team_A.getLeader(), leader);
    }

    TEST_CASE("Add function")
    {
        for (int i = 0; i < 5; i++)
        {
            team_A.add(new Ninja("N", Point(1.0, 1.0)));
        }

        for (int i = 0; i < 4; i++)
        {
            team_A.add(new Cowboy("C", Point(1.0, 1.0)));
        }

        CHECK_EQ(team_A.getTeam().size(), 10);

        CHECK_THROWS(team_A.add(new Ninja("N", Point(1.0, 1.0))));
    }

    TEST_CASE("Attack function")
    {
        Point leaderB_location(1.0, 1.0);
        Cowboy *leaderB = new Cowboy("Bob", leader_location);
        Team team_B(leaderB);

        for (int i = 0; i < 5; i++)
        {
            team_B.add(new Ninja("N", Point(1.0, 1.0)));
        }

        for (int i = 0; i < 4; i++)
        {
            team_B.add(new Cowboy("C", Point(1.0, 1.0)));
        }

        team_A.attack(&team_B);
        CHECK(team_B.getLeader()->getHp() < 110);
    }

    TEST_CASE("stillAlive function")
    {
        CHECK_EQ(team_A.stillAlive(), 10);

        int count = 0;
        for (Character *c : team_A.getTeam())
        {
            c->setHp(0);

            count++;
            if (count == 5)
                break;
        }

        CHECK_EQ(team_A.stillAlive(), 5);
    }
}