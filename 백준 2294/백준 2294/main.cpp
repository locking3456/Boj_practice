#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int n, k;
int coin[100];
int arr[10000] = { 0, };
int main() {
	cin >> n >> k;
	for(int i=0;i<n; i++){
		cin >> coin[i];
	}
	for (int i = 1; i <= k; i++) {
		arr[i] = INF;
		for (int j = 0; j < n; j++) {
			if (i - coin[j] >= 0) {
				arr[i]=min(arr[i], arr[i - coin[j]] + 1);
			}
		}
	}
	if (arr[k]==INF)
		cout << -1;
	else
		cout << arr[k];
}