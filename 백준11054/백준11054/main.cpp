#include <iostream>
using namespace std;
int arr[1000] = { 0, };
int n;
int ascendingNum[1001];
int descendingNum[1001];
int maxNum=0;
void getAsc() {
	for (int i = 1; i <= n; i++) {
		ascendingNum[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				ascendingNum[i]=max(ascendingNum[j] + 1,ascendingNum[i]);
			}
		}
	}
}


void getDsc() {
	for (int i = n; i > 0; i--) {
		descendingNum[i] = 1;
		for (int j = n; j > i; j--) {
			if (arr[i] > arr[j]) {
				descendingNum[i] = max(descendingNum[j] + 1, descendingNum[i]);
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	getAsc();
	getDsc();
	for (int i = 1; i <= n; i++) {
		if (ascendingNum[i]+descendingNum[i] > maxNum) {
			maxNum = ascendingNum[i] + descendingNum[i];
		}
	}

	cout << maxNum-1;
}