#include "Ring.h"
#include <vector>
#include <fstream>
#include <iomanip>

void writeRingsToFile(const std::vector<Ring>& rings, const std::string& fileName)
{
    std::ofstream file(fileName);

    file << "point1X,point1Y,point1Z,point2X,point2Y,point2Z,"
         << "point3X,point3Y,point3Z,point4X,point4Y,point4Z,"
         << "collocX,collocY,collocZ,normalX,normalY,normalZ,"
         << "vorticity\n";

    file << std::setprecision(6) << std::fixed;

    for (const auto& ring : rings)
    {
        for (int index{ 0 }; index < 4; ++index)
        {
            file << ring.getVertices()[index].position.x << ',';
            file << ring.getVertices()[index].position.y << ',';
            file << ring.getVertices()[index].position.z << ',';
        }

        file << ring.getCollocationPoint().position.x << ',';
        file << ring.getCollocationPoint().position.y << ',';
        file << ring.getCollocationPoint().position.z << ',';

        file << ring.getNormalVector().x << ',';
        file << ring.getNormalVector().y << ',';
        file << ring.getNormalVector().z << ',';

        file << ring.getVorticityStrength() << '\n';
    }
}
