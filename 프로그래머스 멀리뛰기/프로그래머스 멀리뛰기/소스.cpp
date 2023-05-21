#include <iostream>
using namespace std;
//long long countnum;
////void dfs(int n, int j) {
//	if (n == j) {
//		countnum++;
//		return;
//	}
//	if (j > n)
//		return;
//	else {
//		dfs(n, j + 1);
//		dfs(n, j + 2);
//	}
//
//}
//long long solution(int n) {
//	dfs(n, 0);
//	long long answer = countnum;
//	return answer;
//}
long long dp[2001];
long long solution(int n) {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2])%1234567;
    }
    long long answer = dp[n];
    return answer;
}
int main() {
    cout << solution(3);

}