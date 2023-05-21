#include <iostream>
using namespace std;
int n, m;
int answer[10];
void solve(int level, int num) {
	if (level == m) {
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << endl;
		return;
	}
	for (int i = num ; i <= n; i++) {
		answer[level] = i;
		solve(i, i);
	}
}
int main() {
	cin >> n >> m;
	solve(1, 0);
}