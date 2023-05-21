#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pqMin;
priority_queue<int, vector<int>> pqMax;
map<int, int>cnt;
void insertpq(int n) {
	pqMax.push(n);
	pqMin.push(n);
	cnt[n]++;
}
void deleteMin() {
	if (!pqMin.empty()) {
		cnt[pqMin.top()]--;
		pqMin.pop();
	}
	while (!pqMax.empty() && cnt[pqMax.top()] == 0) {
		pqMax.pop();
	}
}
void deleteMax() {
	if (!pqMax.empty()) {
		cnt[pqMax.top()]--;
		pqMax.pop();
	}
	while (!pqMin.empty() && cnt[pqMin.top()] == 0) {
		pqMin.pop();
	}
}

int main() {

	int T, n, k;
	char mode;
	cin >> T;
	for (int i = 0; i < T; i++) {
		while (!pqMax.empty()) {
			pqMax.pop();
		}
		while (!pqMin.empty()) {
			pqMin.pop();
		}

		cnt.clear();

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> mode >> n;
			if (mode == 'I') {
				insertpq(n);
			}
			else {
				if (n == 1)
					deleteMax();
				else
					deleteMin();
				while (!pqMax.empty() && cnt[pqMax.top()] == 0) {
					pqMax.pop();
				}
				while (!pqMin.empty() && cnt[pqMin.top()] == 0) {
					pqMin.pop();
				}
			}
		}
		if (pqMax.empty() || pqMin.empty()) {
			cout << "EMPTY\n";
		}
		else cout << pqMax.top() << " " << pqMin.top() << '\n';
	}
	return 0;
}