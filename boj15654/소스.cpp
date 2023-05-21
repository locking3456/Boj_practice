#include <iostream>
#include<cstdio>
#include <algorithm>
using namespace std;
int n, m;
bool isused[10001];
int answer[10];
void solve(int level, int * arr)
{
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << answer[i]<<' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isused[arr[i]])
			continue;
		isused[arr[i]] = true;
		answer[level] = arr[i];
		solve(level + 1,arr);
		isused[arr[i]] = false;
	}
	
}
int main() {
	int* arr;
	scanf("%d", &n);
	scanf("%d", &m);
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	solve(0, arr);
}