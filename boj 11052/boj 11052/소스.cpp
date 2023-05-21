#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
	}
	for (int i = 2; i <= N/2; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[N];
}