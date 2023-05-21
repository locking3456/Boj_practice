#include <iostream>
using namespace std;
int arr[100000];
int dp[100000];
int max(int x,int y) {
	return x > y ? x:y;
}
int main() {
	int inputnum;
	int maxnum;
	cin >> inputnum;
	for (int i = 0; i < inputnum; i++) {
		cin >> arr[i];
	}
	dp[0]=arr[0];
	maxnum = dp[0];
	for (int i = 1; i < inputnum; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	for (int i = 0; i < inputnum; i++) {
		if (dp[i] > maxnum) {
			maxnum = dp[i];
		}
	}
	cout << maxnum;
}