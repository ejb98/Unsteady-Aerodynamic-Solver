#include "Panel.h"
#include <vector>
#include <fstream>
#include <iomanip>

void writePanelsToFile(const std::vector<Panel>& panels, const std::string& fileName)
{
    std::ofstream file(fileName);

    file << "point1X,point1Y,point1Z,point2X,point2Y,point2Z,"
         << "point3X,point3Y,point3Z,point4X,point4Y,point4Z,"
         << "collocX,collocY,collocZ,normalX,normalY,normalZ,"
         << "tangentX,tangentY,tangentZ,area,pressure\n";

    file << std::setprecision(6) << std::fixed;

    for (const auto& panel : panels)
    {
        for (int index{ 0 }; index < 4; ++index)
        {
            file << panel.getVertices()[index].position.x << ',';
            file << panel.getVertices()[index].position.y << ',';
            file << panel.getVertices()[index].position.z << ',';
        }

        file << panel.getCollocationPoint().position.x << ',';
        file << panel.getCollocationPoint().position.y << ',';
        file << panel.getCollocationPoint().position.z << ',';

        file << panel.getNormalVector().x << ',';
        file << panel.getNormalVector().y << ',';
        file << panel.getNormalVector().z << ',';

        file << panel.getTangentVector().x << ',';
        file << panel.getTangentVector().y << ',';
        file << panel.getTangentVector().z << ',';

        file << panel.getArea() << ',';
        file << panel.getPressure() << '\n';
    }
}
