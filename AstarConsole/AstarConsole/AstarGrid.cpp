#include "AstarGrid.h"
#include <fstream>
#include <cmath>

AstarGrid::AstarGrid(int sizeX, int sizeY, int sizeZ, float nodeSize, float worldX, float worldY, float worldZ)
    : gridSizeX(sizeX), gridSizeY(sizeY), gridSizeZ(sizeZ), nodeSize(nodeSize), worldPointX(worldX), worldPointY(worldY), worldPointZ(worldZ) {
    grid.resize(gridSizeX, std::vector<std::vector<AstarNode*>>(gridSizeY, std::vector<AstarNode*>(gridSizeZ, nullptr)));
    nodeHalfLength = nodeSize / 2;
}

AstarGrid::~AstarGrid() {
    for (auto& layer : grid) {
        for (auto& row : layer) {
            for (auto& node : row) {
                delete node;
            }
        }
    }
}

void AstarGrid::SetNodeWalkable(int x, int y, int z, bool isWalkable) {
    Vector3 worldPoint(x * nodeHalfLength * 2 + worldPointX + nodeHalfLength, y * nodeHalfLength * 2 + worldPointY + nodeHalfLength, z * nodeHalfLength * 2 + worldPointZ + nodeHalfLength);
    if (grid[x][y][z] == nullptr) {
        grid[x][y][z] = new AstarNode(isWalkable, worldPoint, x, y, z);
    }
    else {
        grid[x][y][z]->IsWalkable = isWalkable;
    }
}

void AstarGrid::CreateGrid() {
    for (int x = 0; x < gridSizeX; x++) {
        for (int y = 0; y < gridSizeY; y++) {
            for (int z = 0; z < gridSizeZ; z++) {
                Vector3 worldPoint(x * nodeHalfLength * 2 + worldPointX, y * nodeHalfLength * 2 + worldPointY, z * nodeHalfLength * 2 + worldPointZ);
                grid[x][y][z] = new AstarNode(grid[x][y][z]->IsWalkable, worldPoint, x, y, z);
            }
        }
    }
}

AstarNode* AstarGrid::NodeFromWorldPoint(const Vector3& worldPosition) {
    int x = static_cast<int>(std::clamp(worldPosition.x / (gridSizeX * nodeHalfLength * 2), 0.0f, 1.0f) * (gridSizeX - 1));
    int y = static_cast<int>(std::clamp(worldPosition.y / (gridSizeY * nodeHalfLength * 2), 0.0f, 1.0f) * (gridSizeY - 1));
    int z = static_cast<int>(std::clamp(worldPosition.z / (gridSizeZ * nodeHalfLength * 2), 0.0f, 1.0f) * (gridSizeZ - 1));
    return grid[x][y][z];
}

std::vector<AstarNode*> AstarGrid::GetNeighbours(AstarNode* node) {
    std::vector<AstarNode*> neighbours;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            for (int dz = -1; dz <= 1; dz++) {
                if (dx == 0 && dy == 0 && dz == 0) {
                    continue; // Skip the current node
                }

                int checkX = node->GridX + dx;
                int checkY = node->GridY + dy;
                int checkZ = node->GridZ + dz;

                if (checkX >= 0 && checkX < gridSizeX &&
                    checkY >= 0 && checkY < gridSizeY &&
                    checkZ >= 0 && checkZ < gridSizeZ) {
                    neighbours.push_back(grid[checkX][checkY][checkZ]);
                }
            }
        }
    }

    return neighbours;
}

void AstarGrid::SaveUnwalkableNodesToFile(const std::string& filePath) {
    std::ofstream outFile(filePath);
    if (!outFile.is_open()) {
        return; // 파일 열기 실패 시 종료
    }

    for (int x = 0; x < gridSizeX; ++x) {
        for (int y = 0; y < gridSizeY; ++y) {
            for (int z = 0; z < gridSizeZ; ++z) {
                AstarNode* node = grid[x][y][z];
                if (node && !node->IsWalkable) {
                    outFile << "Node: ("
                        << node->GridX << ", "
                        << node->GridY << ", "
                        << node->GridZ << ")\n";
                }
            }
        }
    }

    outFile.close();
}

