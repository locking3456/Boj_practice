#include<iostream>
using namespace std;
int n, m;
int arr[500][500];
bool isVisited[500][500] = { 0, };
int maxNum = 0;
//¼¼·Î 1ÀÚ
bool canGo(int px, int py) {
	if (px >= 0 && px < n && py >= 0 && py < m && !isVisited[px][py]) {
		return true;
	}
	else
		return false;
}
void dfs(int x, int y, int cnt , int sum) {
	if (cnt == 4) {
		if (sum > maxNum) {
			maxNum = sum;
		}
	}
	else {
		if (canGo(x + 1, y)) {
			isVisited[x + 1][y] = true;
			dfs(x + 1, y, cnt + 1, sum + arr[x+1][y]);
			isVisited[x + 1][y] = false;
		}
		if (canGo(x - 1, y)) {
			isVisited[x - 1][y] = true;
			dfs(x - 1, y, cnt + 1, sum + arr[x-1][y]);
			isVisited[x - 1][y] = false;
		}
		if (canGo(x , y+1)) {
			isVisited[x][y+1] = true;
			dfs(x , y+1, cnt + 1, sum + arr[x][y+1]);
			isVisited[x][y + 1] = false;
		}
		if (canGo(x , y-1)) {
			isVisited[x ][y-1] = true;
			dfs(x , y-1, cnt + 1, sum + arr[x][y-1]);
			isVisited[x][y - 1] = false;
		}
	}
}

void mountatinShape(int startX, int startY) {
	if (canGo(startX + 1, startY) && canGo(startX, startY - 1) && canGo(startX,startY + 1) && canGo(startX, startY)) {
		int sum = 0;
		sum = arr[startX + 1][startY] + arr[startX][startY - 1] + arr[startX][startY + 1] + arr[startX][startY];
		if (sum > maxNum)
			maxNum = sum;
	}
	if (canGo(startX - 1, startY) && canGo(startX, startY - 1) && canGo(startX, startY + 1) && canGo(startX, startY)) {
		int sum = 0;
		sum = arr[startX - 1][startY] + arr[startX][startY - 1] + arr[startX][startY + 1] + arr[startX][startY];
		if (sum > maxNum)
			maxNum = sum;
	}

	if (canGo(startX + 1, startY) && canGo(startX -1, startY) && canGo(startX, startY + 1) && canGo(startX, startY)) {
		int sum = 0;
		sum = arr[startX + 1][startY] + arr[startX-1][startY] + arr[startX][startY + 1] + arr[startX][startY];
		if (sum > maxNum)
			maxNum = sum;
	}
	if (canGo(startX + 1, startY) && canGo(startX - 1, startY) && canGo(startX, startY - 1) && canGo(startX, startY)) {
		int sum = 0;
		sum = arr[startX + 1][startY] + arr[startX - 1][startY] + arr[startX][startY - 1] + arr[startX][startY];
		if (sum > maxNum)
			maxNum = sum;
	}
}
void tet1(int startX, int startY) {
	isVisited[startX][startY] = true;
	dfs(startX, startY, 1,arr[startX][startY]);
	isVisited[startX][startY] = false;

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
			mountatinShape(i, j);
			tet1(i, j);
		}
	}

	cout << maxNum;
}