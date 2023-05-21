#include <iostream>
using namespace std;
int tri[501][501];
int dp[501][501];

int max(int x, int y) {
	return x > y ? x : y;
}
int main() {
	int trisize;
	cin >> trisize;
	int maxnum = 0;

	for (int i = 0; i < trisize; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> tri[i][j];
		}
	}
	dp[0][0] = tri[0][0];
	for (int j = 1; j < trisize; j++) {
		for (int k = 0; k <= j; k++) {
			if (k == 0) {
				dp[j][k] = tri[j][k]+ dp[j - 1][k];
			}
			else if (k == j) {
				dp[j][k] = tri[j][k] + dp[j - 1][k-1];
			}
			else {
				dp[j][k] = max((tri[j][k] + dp[j - 1][k]), (tri[j][k] + dp[j - 1][k - 1]));
			}
		}

	}
	for (int i = 0; i < trisize; i++) {
		if (dp[trisize-1][i] > maxnum) {
			maxnum = dp[trisize - 1][i];
		}
	}
	cout << maxnum;
}