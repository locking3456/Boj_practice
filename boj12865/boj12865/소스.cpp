#include <iostream>
#include <algorithm>
using namespace std;
long long dp[101][100001];//가방 물건의 번호,내가방의 무게
int W[101];
int V[101];
int main() {
	int maxItemNum;
	int maxItemWeight;
	cin >> maxItemNum >> maxItemWeight;

	for(int i=1; i<=maxItemNum; i++){
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= maxItemNum; i++) {
		for (int j = 1; j <= maxItemWeight; j++) {
			if (j - W[i]>=0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[maxItemNum][maxItemWeight];
}