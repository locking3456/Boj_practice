#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int directionX[4] = { 1, 0, -1, 0 };
int directionY[4] = { 0, 1, 0, -1 };
int isVisited[501][501] = { 0, };
map<int, int> sizeOfOil;
int sizeOfLandX;
int sizeOfLandY;
int areaNum = 1;
vector<vector<int>> oilMap;
void BFS(int startX, int startY ) {
    int tmp = 0;
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    oilMap[startX][startY] = areaNum;
    isVisited[startX][startY] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        tmp++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = x + directionX[i];
            int nextY = y + directionY[i];
            if (nextX >= 0 && nextX < sizeOfLandX && nextY >= 0 && nextY < sizeOfLandY && isVisited[nextX][nextY] == false && oilMap[nextX][nextY]>0) {
                oilMap[nextX][nextY] = areaNum;
                isVisited[nextX][nextY] = 1;
                q.push({ nextX,nextY });
            }
        }
    }
    sizeOfOil[areaNum] = tmp;
    areaNum++;
   
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    oilMap = land;
    sizeOfLandX = land.size(); //열의 길이
    sizeOfLandY = land[0].size(); //행의 길이

    for (int i = 0; i < sizeOfLandX; i++) {
        for (int j = 0; j < sizeOfLandY; j++) {
            if (isVisited[i][j] == false && land[i][j] == 1) {
                BFS(i, j);
            }
        }
    }

    for (int j = 0; j < sizeOfLandY; j++) {
        set<int> oilSet;
        int sumOfOil=0;
        for (int i = 0; i < sizeOfLandX; i++) {
            oilSet.insert(oilMap[i][j]);
        }
        set<int>::iterator iter;
        for (auto it : oilSet) {
            sumOfOil += sizeOfOil[it];
        }
        answer = max(answer, sumOfOil);
    }

    return answer;
}
