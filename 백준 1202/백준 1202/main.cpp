#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> pq;
int bag[300000];
pair<int, int> jewerly[300000];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		jewerly[i] = { temp1,temp2 };
	}

	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}

	sort(jewerly, jewerly + n);
	sort(bag, bag + k);

	int idx=0;
	long long sum = 0;

	for (int i = 0; i < k; i++) {
		while (idx < n && bag[i] >= jewerly[idx].first) {
			pq.push(jewerly[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
}
