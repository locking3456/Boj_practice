#include <iostream>
#include <set>
using namespace std;
int arr[500][500];
int dp[500][500];
int m, n;
int cnt;
int xidx[4] = { 1,0,-1,0 };
int yidx[4] = { 0,1,0,-1 };
bool canGo(int x, int y, int height) {
	if (x >= 0 && x < m && y>=0 && y < n && height > arr[x][y])
		return true;
	else
		return false;
}

int dfs(int x,int y) {
	if (x == m - 1 && y == n - 1) {
		return 1;
	}
	if (dp[x][y] != -1)
	{
		return dp[x][y];
	}

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		if (canGo(x + xidx[i], y + yidx[i], arr[x][y])) {
			dp[x][y] = dp[x][y] + dfs(x + xidx[i],y + yidx[i]);
		}
	}
	return dp[x][y];
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(0, 0);
}