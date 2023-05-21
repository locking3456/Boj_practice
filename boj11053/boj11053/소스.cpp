//#include<iostream>
//using namespace std;
//int main() {
//	int dp1[1001] = { 0, };
//	int dp2[1001] = { 0, };
//	int inputn;
//	int checknum = 0;
//	int j = 1;
//	cin >> inputn;
//	for (int i = 0; i < inputn; i++) {
//		cin >> dp1[i];
//	}
//	dp2[0] = dp1[0];
//	for (int k = 0; k < j; k++) {
//		for (int i = 0; i < inputn; i++) {
//			for (int l = 0; l <= k; l++) {
//				if (dp2[l] == dp1[i]) {
//					checknum = 1;
//					break;
//		
//				}
//			}
//			if (checknum == 1) {
//				checknum = 0;
//				continue;
//			}
//			dp2[k + 1] = dp1[i];
//			j++;
//			break;
//		}
//	}
//	
//	cout << j;
//	
//}
#include <iostream>
using namespace std;
int max(int x, int y)
{
	return x > y ? x : y;
}
int main() {
	int arr[1001];
	int dp[1001]; //자신 까지의 증가 수열 수
	int maxnum=0;
	int inputn;
	cin >> inputn;
	for (int i = 0; i < inputn; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 1; i < inputn; i++) {
		for (int j = 0; j <= i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	
	for (int i = 0; i < inputn; i++) {
		if (dp[i] > maxnum)
			maxnum = dp[i];
	}

	cout << maxnum;
}