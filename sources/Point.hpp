#pragma once

#include <iostream>

const double EPSILON = 0.001;

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

        static Point moveTowards(Point &originPoint, Point &destinationPoint, double distance);

        bool operator==(const Point &other) const;
    };
}