#include <iostream>
#include<bitset>
#include <queue>
#include <cstring>
using namespace  std;
int arr[50][50];
bool isVisited[50][50];
int n, m;
int maxCnt = 1;
int xi[4] = { 0,1,0,-1 };
int yi[4] = { 1,0,-1,0 };
queue<pair<int, int>> bfsq;
bool canGo(int x, int y , int z) {
	if (x >= 0 && x < m && y >= 0 && y < n && !isVisited[x][y]) {
		if (arr[x][y] & (1 << z)) {
			return false;
		}
		else
			return true;
	}
	return false;
}
bool canGo(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n ) {
		return true;
	}
	return false;
}

void bfs(int startX, int startY) {
	bfsq.push({ startX,startY });
	isVisited[startX][startY] = true;
	int cnt = 1;
	while (!bfsq.empty()) {
		int col = bfsq.front().first;
		int row = bfsq.front().second;
		bfsq.pop();
		for (int i = 0; i < 4; i++) {
			if (canGo(col + xi[i], row + yi[i],i)) {
				bfsq.push({ col + xi[i] , row + yi[i] });
				isVisited[col + xi[i]][row + yi[i]] = 1;
				cnt += 1;
				if (maxCnt < cnt)
					maxCnt = cnt;
			}
		}
	}
}
int main() {
	int roomCnt=0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (isVisited[i][j])
				continue;
			roomCnt += 1;
			bfs(i, j);
		}
	}
	cout << roomCnt << endl;
	cout << maxCnt << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++){
			for (int k = 0; k < 4; k++) {
				if (canGo(i + xi[k], j + yi[k]) && (arr[i + xi[k]][j + yi[k]] &(1<<k))) {
					memset(isVisited, 0, sizeof(isVisited));
					arr[i + xi[k]][j + yi[k]] ^= (1 << k);
					bfs(i, j);
					arr[i + xi[k]][j + yi[k]] |= (1 << k);
				}
			}
		}
	}

	cout << maxCnt;
}