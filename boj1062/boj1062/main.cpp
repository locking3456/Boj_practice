#include <iostream>
#include <string>
using namespace std;
string arr[50];
int wordNum[50] = { 0, };
int n, k;
int result = 0;
// 조합을 위한 dfs
void dfs(int alpha, int level, int idx) {
	if (k == level) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((alpha & wordNum[i]) == wordNum[i])
				cnt++;
		}
		if (cnt > result) {
			result = cnt;
		}
	}
	else {
		int x = 0;
		for (int i = idx; i < 26; i++) {
			x = 1 << i;
			if (alpha & x)continue;
			else {
				alpha |= x;
				dfs(alpha, level + 1, i);
				alpha ^= x;
			}
		}
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	int alpha = 0;
	alpha |= (1 << ('a' - 'a'));
	alpha |= (1 << ('n' - 'a'));
	alpha |= (1 << ('t' - 'a'));
	alpha |= (1 << ('i' - 'a'));
	alpha |= (1 << ('c' - 'a'));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			wordNum[i] |= 1 << (arr[i][j] - 'a');
		}
	}
	k = k - 5;
	dfs(alpha, 0, 0);
	cout << result;
}

