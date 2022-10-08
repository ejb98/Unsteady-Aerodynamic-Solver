#include "Point.h"
#include <array>

double calculateArea(const std::array<Point, 4>& vertices)
{
    // Calculate area of a trapezoid, assuming sideA and sideB are parallel to each other.
    double widthH{ vertices[1].position.y - vertices[0].position.y };
    double sideA{ vertices[3].position.x - vertices[0].position.x };
    double sideB{ vertices[2].position.x - vertices[1].position.x };

    double area{ (sideA + sideB) * widthH / 2.0 };

    return area;
}