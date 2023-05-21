#include <iostream>
using namespace std;
int max(int x, int y)
{
	return x > y ? x : y;
}
int main() {
	int inputn = 0;
	int stair[301] = { 0, };
	int dp[301] = { 0, };
	cin >> inputn;
	for (int i = 0; i < inputn; i++) {
		cin >> stair[i];
	}
	dp[0] = stair[0];
	dp[1] = max(stair[1] + dp[0],stair[1]);
	dp[2] = max(stair[2]+stair[1], dp[0]+stair[2]);

	for (int i = 3; i < inputn; i++) {
		dp[i] = max(stair[i] + stair[i - 1] + dp[i - 3], dp[i - 2] + stair[i]);
	}
	cout << dp[inputn-1];
}