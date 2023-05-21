#include <iostream>
using namespace std;
int n, m;
bool isused[10];
int answer[10];
void solve(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (isused[i])
			continue;
		isused[i] = 'true';
		answer[level] = i;
		solve(level + 1);
		isused[i] = false;
	}
}
int main() {
	cin >> n >> m;
	solve(0);
}