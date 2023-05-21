#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001];
int arr[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int j = 3; j <= n + 1; j++) {
		dp[j] = dp[j - 1];
		dp[j] = max(dp[j], dp[j - 2] + arr[j]);
		dp[j] = max(dp[j], dp[j - 3] + arr[j - 1] + arr[j]);

	}
	cout << dp[n] << endl;
}