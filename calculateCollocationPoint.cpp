#include "Point.h"
#include "Position.h"
#include <array>

Point calculateCollocationPoint(const std::array<Point, 4>& vertices)
{
    double positionX{};
    double positionY{};
    double positionZ{};

    for (const auto& vertex : vertices)
    {
        positionX += vertex.position.x;
        positionY += vertex.position.y;
        positionZ += vertex.position.z;
    }

    Position position{ positionX / 4.0, positionY / 4.0, positionZ / 4.0 };

    Point collocationPoint{ position };

    return collocationPoint;
}