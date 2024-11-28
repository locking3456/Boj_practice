#include "AstarGrid.h"
#include "AstarPathfinding.h"
#include <fstream>
#include <iostream>


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: AstarProgram <path_to_json_file>" << std::endl;
        return 1;
    }

    // Load grid data from JSON file
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open JSON file: " << argv[1] << std::endl;
        return 1;
    }

    json gridData;
    inputFile >> gridData;

    // Parse grid dimensions and nodes
    int sizeX = gridData["gridSizeX"];
    int sizeY = gridData["gridSizeY"];
    int sizeZ = gridData["gridSizeZ"];
    float nodeSize = gridData["nodeSize"];
    AstarGrid grid(sizeX, sizeY, sizeZ, nodeSize);

    for (const auto& node : gridData["unwalkableNodes"]) {
        AstarNode* n = grid.NodeFromWorldPoint({ node["x"], node["y"], node["z"] });
        if (n) n->IsWalkable = false;
    }

    // Initialize pathfinding
    AstarPathfinding pathfinder(&grid);

    Vector3 start = { gridData["start"]["x"], gridData["start"]["y"], gridData["start"]["z"] };
    Vector3 end = { gridData["end"]["x"], gridData["end"]["y"], gridData["end"]["z"] };

    auto path = pathfinder.FindPath(start, end);

    // Save path to JSON
    std::string outputPath = "C:\\Users\\Public\\AstarPath.json";
    std::ofstream outputFile(outputPath);
    outputFile << AstarPathfinding::SerializePathToJSON(path);
    std::cout << "Path saved to: " << outputPath << std::endl;

    return 0;
}
