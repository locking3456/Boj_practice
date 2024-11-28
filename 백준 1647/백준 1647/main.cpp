#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 가중치 start end순
vector<pair<int, pair<int, int>>> inputData;
int parent[100001] = { 0, };

int findParent(int x) {
	if (parent[x] == x)
		return x;
	else return parent[x] = findParent(parent[x]);
}

bool sameParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x == y)
		return true;
	else
		return false;
}
void uni(int  x, int y) {
	x = findParent(x);
	y = findParent(y);
	parent[y] = x;
}
int main() {
	int  v, e;
	long long cost;
	cost = 0;
	int cnt = 0;
	cin >> v >> e;
	int tmp1, tmp2, tmp3;
	for (int i = 0; i < e; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		inputData.push_back({ tmp3,{tmp1,tmp2} });
	}

	sort(inputData.begin(), inputData.end());
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < inputData.size(); i++) {
		if (!sameParent(inputData[i].second.first, inputData[i].second.second)) {
			uni(inputData[i].second.first, inputData[i].second.second);
			cost += inputData[i].first;
			cnt += 1;
			if (cnt == v - 1) {
				cost -= inputData[i].first;
			}
		}
	}
	cout << cost;
}