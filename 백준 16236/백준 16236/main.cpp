#include <iostream>
#include <queue>
using namespace std;
int n;
int arr[20][20] = { 0, };
int fishMap[20][20] = { 0, };
bool isVisited[20][20];
int fishSize = 2;
int eatFish = 0;
int cnt = 0;
queue<pair<int,pair<int, int>>>  bfsQ;

bool CanEat(int x, int y) {
	if (arr[x][y]>0&&arr[x][y] < fishSize) {
		return true;
	}
	return false;
}
bool canGo(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n && !isVisited[x][y] && (CanEat(x, y) || arr[x][y] == 0 || arr[x][y]==fishSize))
		return true;
	else
		return false;
}

void Bfs(int x, int y) {
	bfsQ.push({ cnt,{x,y} });
	arr[x][y] = 0;
	int startX, startY, cost;
	int otherX, otherY, otherCost;
	while (!bfsQ.empty()) {
		startX = bfsQ.front().second.first;
		startY = bfsQ.front().second.second;
		cost = bfsQ.front().first;
		bfsQ.pop();
		if (CanEat(startX, startY)) {
			cnt += cost;
			while (!bfsQ.empty()) {
		
				otherX = bfsQ.front().second.first;
				otherY = bfsQ.front().second.second;
				otherCost = bfsQ.front().first;
				if (CanEat(otherX, otherY) && otherCost<=cost) {
					if (otherX < startX) {
						startX = otherX;
						startY = otherY;
						otherCost = cost;
					}
					else if (otherX == startX && startY>otherY ) {
						startX = otherX;
						startY = otherY;
						otherCost = cost;
					}
				}

				bfsQ.pop();
				
			}
			bfsQ.push({ 0, {startX, startY}});
			eatFish += 1;
			if (eatFish == fishSize) {
				fishSize += 1;
				eatFish = 0;
			}
			arr[startX][startY] = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					isVisited[i][j] = false;
				}
			}
			isVisited[startX][startY] = true;
			cost = 0;
		}

		if (canGo(startX-1,startY)) {
			bfsQ.push({ cost + 1,{startX -1,startY}});
			isVisited[startX - 1][startY] = 1;
		}
		if (canGo(startX, startY-1)) {
			bfsQ.push({ cost + 1,{startX ,startY - 1} });
			isVisited[startX][startY-1] = 1;
		}
		if (canGo(startX , startY+1)) {
			bfsQ.push({ cost + 1,{startX ,startY + 1} });
			isVisited[startX][startY + 1] = 1;
		}
		if (canGo(startX+1 , startY)) {
			bfsQ.push({ cost + 1,{startX + 1,startY} });
			isVisited[startX + 1][startY] = 1;
		}
	}

}
int main() {
	cin >> n;
	int startIdxCol, startIdxRow;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				startIdxCol = i;
				startIdxRow = j;
			}
		}
	}

	Bfs(startIdxCol, startIdxRow);
	cout << cnt;
}