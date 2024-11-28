#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N, K;
long long cnt;
long long GetCntOfLessNum(long long num) {
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += min(num / i, N);
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	long long low, high, mid;
	low = 1;
	high = N*N;
	while (low <= high) {
		mid = (low + high) / 2;
		cnt = GetCntOfLessNum(mid);

		if (cnt >= K) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << low;
}