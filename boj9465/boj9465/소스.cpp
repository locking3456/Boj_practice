#include <iostream>
#include <algorithm>
int dp[100001][2];
int card[100001][2];
using namespace std;
int main() {
	int T;//테스트케이스
	int n;//해당하는 스티커의 점수
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> card[k][j];
			}
		}
               
		dp[1][0] = card[1][0];
		dp[1][1] = card[1][1];
		for (int l = 2; l <= n; l++) {
			dp[l][0] = max(dp[l - 1][1] + card[l][0], dp[l - 2][1] + card[l][0]);
			dp[l][1] = max(dp[l - 1][0] + card[l][1], dp[l - 2][0] + card[l][1]);
		}
		cout << max(dp[n][0], dp[n][1])<<'\n';
	}
}