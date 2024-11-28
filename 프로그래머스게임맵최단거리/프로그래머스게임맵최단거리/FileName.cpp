#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int arr[100][100] = { 0, };
int goX[4] = { 0,1,0,-1 };
int goY[4] = { 1,0,-1,0 };
queue<pair<int, pair<int, int>>> bfsQ;
vector<vector<int>> globalMaps;
int n, m;
bool canGo(int x, int y) {
    if (x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 0 && globalMaps[x][y] == 1) {
        return true;
    }
    else
        return false;
}
void BFS(int startX, int startY) {
    bfsQ.push({ 1,{startX,startY} });
    arr[startX][startY] = 1;
    while (!bfsQ.empty()) {
        int x, y, cost;
        x = bfsQ.front().second.first;
        y = bfsQ.front().second.second;
        cost = bfsQ.front().first;
        bfsQ.pop();
        for (int i = 0; i < 4; i++) {
            int nextX, nextY, nextCost;
            nextX = x + goX[i];
            nextY = y + goY[i];
            nextCost = cost + 1;
            if (canGo(nextX, nextY)) {
                bfsQ.push({ nextCost,{nextX,nextY} });
                arr[nextX][nextY] = nextCost;
            }
        }
    }
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps[0].size();
    m = maps.size();
    globalMaps = maps;
    BFS(0, 0);
    if (arr[m - 1][n - 1] == 0) {
        answer = -1;
    }
    else
        answer = arr[m - 1][n - 1];
    return answer;
}
int main() {
    vector<vector<int>> maps(1, std::vector<int>(5, 0));
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> maps[i][j];
        }
    }
    cout << solution(maps);
}