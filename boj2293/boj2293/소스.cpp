#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int coin[101];

int dp[10001];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= m; j++) {
			if (dp[j - coin[i]]) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	cout << dp[m];

}