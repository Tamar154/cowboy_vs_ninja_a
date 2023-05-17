#include "Point.hpp"

namespace ariel
{   
    
    // Point::Point() : _x(0), _y(0) {}

    Point::Point(double x, double y) : _x(x), _y(y) {}

    double Point::getX() { return _x; }
    double Point::getY() { return _y; }

    void Point::setX(double xVal) { _x = xVal; }
    void Point::setY(double yVal) { _y = yVal; }

    double Point::distance(Point p)
    {
        return -1;
    }

    void Point::Print()
    {
    }

    Point Point::moveTowards(Point &originPoint, Point &destinationPoint, double distance)
    {
        return *this;
    }

}