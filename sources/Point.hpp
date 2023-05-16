#pragma once

#include <iostream>

namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;

    public:
        Point(double xVal, double yVal);

        double getX();
        double getY();

        void setX(double xVal);
        void setY(double yVal);

        double distance(Point other);

        void Print();

        double moveTowards(double originPoint, double destinationPoint, double distance);
    };
}