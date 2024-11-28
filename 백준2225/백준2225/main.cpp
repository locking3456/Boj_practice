#include <iostream>
using namespace std;
long long m = 1000000000;
long long dp[204][204];
int main() {
	long long n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}


	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int z = 0; z <= j; z++) {
				dp[i][j] += dp[i - 1][z];
			}
			dp[i][j] %= m;
		}
	}
	cout << dp[k][n];
}

