#include <iostream>
#include <queue>
using namespace std;
int arr[300][300];
int iceMelt[300][300];
bool isVisited[300][300] = { 0, };
int n, m;
int arrX[4] = { 1,0,-1,0 };
int arrY[4] = { 0,1,0, - 1};

bool canGo(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y]>0)
		return true;
	else
		return false;
}
int getAdjacent(int x, int y) {
	int sea=0;
	for (int i = 0; i < 4; i++) {
		if (arr[x + arrX[i]][y + arrY[i]]==0) {
			sea += 1;
		}
	}
	return sea;
}
void bfs(int startX, int startY) {
	queue<pair<int, int>> bfsQ;
	int cnt;
	bfsQ.push({ startX,startY });
	isVisited[startX][startY] = true;
	while (!bfsQ.empty()) {
		int x = bfsQ.front().first;
		int y = bfsQ.front().second;
		bfsQ.pop();
		for (int i = 0; i < 4; i++) {
			if (!isVisited[x+arrX[i]][y+arrY[i]] && canGo(x, y)) {
				bfsQ.push({ x + arrX[i], y + arrY[i] });
				isVisited[x + arrX[i]][y + arrY[i]] = true;
			}
		}
	}
}
int main() {
	int year=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	while (cnt < 2) {
		cnt = 0;
		int iceTotal = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!isVisited[i][j] && arr[i][j]>0) {
					cnt += 1;
					bfs(i, j);

				}
				iceMelt[i][j] = getAdjacent(i, j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				isVisited[i][j] = false;
				if (arr[i][j] > 0) {
					arr[i][j] -= iceMelt[i][j];
					iceMelt[i][j] = 0;
					if (arr[i][j] < 0)
						arr[i][j] = 0;
				}
			}
		}
		if (cnt == 0) {
			year = 0;
			break;
		}
		if (cnt >= 2) {
			break;
		}
		year++;
	}
	cout << year;
}