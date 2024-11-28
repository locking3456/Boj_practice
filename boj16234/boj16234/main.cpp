#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int arr[50][50];
bool isVisited[50][50];
queue<pair<int, int>> bfsq;
queue<pair<int, int>> visitedq;
int n, l, r;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool canGo(int x, int y, int nx, int ny) {
	if (nx >= 0 && nx < n && ny>=0 && ny < n && !isVisited[nx][ny]) {
		if (abs(arr[nx][ny] - arr[x][y])>=l && abs(arr[nx][ny] - arr[x][y])<=r) {
			return true;
		}
		return false;
	}
	else {
		return false;
	}
}
bool bfs(int sX, int sY) {
	bfsq.push({ sX,sY });
	visitedq.push({ sX,sY });
	isVisited[sX][sY] = true;

	int cx, cy , nx, ny ,population, nationCount;
	int avrPop=0;
	population = arr[sX][sY];
	nationCount = 1;
	while (!bfsq.empty()) {
		cx = bfsq.front().first;
		cy = bfsq.front().second;
		bfsq.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (canGo(cx, cy, nx,ny)) {
				bfsq.push({ nx, ny });
				visitedq.push({ nx, ny });
				isVisited[nx][ny] = true;
				population += arr[nx][ny];
				nationCount += 1;
			}
		}
	}
	avrPop = population / nationCount;

	while (!visitedq.empty()) {
		arr[visitedq.front().first][visitedq.front().second] = avrPop;
		visitedq.pop();
	}

	if (nationCount > 1)
		return false;
	else {
		isVisited[sX][sY] = false;
		return true;
	}
}
int main() {
	cin >> n >> l >> r;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		bool canBreak = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(!isVisited[i][j])
					canBreak=bfs(i, j)&&canBreak;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				isVisited[i][j] = false;
			}
		}
		if (canBreak)
			break;
		cnt += 1;
	}
	cout << cnt;

}