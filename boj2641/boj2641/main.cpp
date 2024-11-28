#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001][1001];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	//각 행이 가리키고 있는 인덱스의 값을 저장
	vector<int> vidx(n);
	for (int i = 0; i < n; i++) {
		sort(arr[i], arr[i] + m);
		vidx[i] = 0;
	}
	int minidx = -1;
	int answ = 1000000001;
	while (1) {
		int minVal = 1000000001;
		int maxVal = -1;
		for (int i = 0; i < n ; i++) {
			if (minVal > arr[i][vidx[i]]) {
				minidx = i;
				minVal = arr[i][vidx[i]];
			}
			if (maxVal < arr[i][vidx[i]]) {
				maxVal = arr[i][vidx[i]];
			}
		}

		answ = min(answ, maxVal - minVal);
		vidx[minidx] += 1;
		if (vidx[minidx] == n) {
			break;
		}
	}
	cout << answ;
}