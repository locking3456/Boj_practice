#include <iostream>
#define INF 987654321
using namespace std;
int dp[401][401];

int v, e;
void floyd() {
	//k는 경유점
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}
int main() {
	int maxValue = INF;
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j)
				dp[i][j] == 0;
			else
				dp[i][j] = INF;
			
		}
	}
	for (int i = 0; i < e; i++) {
		int from, to, value;
		cin >> from >> to >> value;
		dp[from][to] = value;
	}

	floyd();

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (dp[i][j] + dp[j][i] < maxValue && !(i==j)) {
				maxValue = dp[i][j] + dp[j][i];
			}
		}
	}
	if (maxValue >= INF) {
		cout << -1;
	}
	else {
		cout << maxValue;
	}
}