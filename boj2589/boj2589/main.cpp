#include<iostream>
#include<queue>
using namespace std;
int n, m;
char arr[50][50];
int isVisited[50][50] = { 0, };
int maxLength=0;
queue<pair<int, int>>bfsQ;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool canGo(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && !isVisited[x][y] && arr[x][y]=='L')
		return true;
	else
		return false;
}
void bfs(int sx, int sy) {
	bfsQ.push({ sx,sy });
	isVisited[sx][sy] = 1;
	while (!bfsQ.empty()) {
		int sx = bfsQ.front().first;
		int sy = bfsQ.front().second;
		int distance = isVisited[sx][sy];
		bfsQ.pop();
		for (int i = 0; i < 4; i++) {
			if (canGo(sx + dx[i], sy + dy[i])) {
				bfsQ.push({sx + dx[i],sy + dy[i]});
				isVisited[sx + dx[i]][sy + dy[i]] = distance + 1;
			}
		}
	}
}
int getMaxValue() {
	int maxValue=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maxValue=max(maxValue, isVisited[i][j]);
		}
	}
	return maxValue-1;
}
void InitIsVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			isVisited[i][j] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (canGo(i, j)) {
				bfs(i, j);
				maxLength = max(maxLength, getMaxValue());
				InitIsVisited();
			}
		}
	}
	cout << maxLength;
}