#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int parent[1001];
vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> inputData(1001);
int findParent(int x) {
	if (parent[x] == x)
		return x;
	else return parent[x] = findParent(parent[x]);
}
bool isSameParent(int x, int y) {
	int parentOfX = findParent(x);
	int parentOfY = findParent(y);
	if (parentOfX == parentOfY) {
		return true;
	}
	else {
		return false;
	}
}

void uni(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	parent[y] = x;
}
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	int com1 = 0, com2 = 0, cost = 0,result=0;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		inputData[from].push({ cost,to });
		inputData[to].push({ cost,from });
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i < n ; i++) {
		while (!inputData[1].empty()) {
			com1 = 1;
			com2 = inputData[1].top().second;
			cost = inputData[1].top().first;
			inputData[1].pop();
			if (!isSameParent(com1, com2)) {
				result += cost;
				uni(com1, com2);
				while (!inputData[com2].empty()) {
					inputData[com1].push(inputData[com2].top());
					inputData[com2].pop();
				}
				break;
			}
		}
	}
	cout << result;
}