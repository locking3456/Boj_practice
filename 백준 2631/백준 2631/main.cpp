#include <iostream>
#include <algorithm>
using namespace std;
int arr[200];
int dp[200] = { 0, };
int lis = 0;
int main() {
	int n,x,y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <i; j++) {
			if (arr[i] > arr[j]) {
				dp[i]=max(dp[i], dp[j] + 1);
				lis = max(lis, dp[i]);
			}
		}
	}
	cout << n-lis;
}