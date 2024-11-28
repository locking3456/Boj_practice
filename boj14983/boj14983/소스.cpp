#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#define INT_MAX 2147483647
using namespace std;
int NumOfItem[101];
vector<pair<int, int>> dijkstraV[101];
vector<int> distanceV(101);

void dijkstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // 비용 노드
	pq.push(make_pair(0, start));
	distanceV[start] = 0;
	while (!pq.empty()) {
		int distanceOfTo = pq.top().first;
		int toVertex = pq.top().second;
		pq.pop();

		if (distanceOfTo > distanceV[toVertex]) {
			continue;
		}

		for (int i = 0; i < (int)dijkstraV[toVertex].size(); i++) {
			int cost = distanceOfTo + dijkstraV[toVertex][i].second;
			if (cost < distanceV[dijkstraV[toVertex][i].first]) {
				distanceV[dijkstraV[toVertex][i].first] = cost;
				pq.push(make_pair(cost, dijkstraV[toVertex][i].first));
			}
		}
	}
}

int getNumOfItem(int idx, int n, int m) {
	int sum=0;
	for (int i = 1; i <= n; i++) {
		if (distanceV[i] <= m) {
			sum += NumOfItem[i];
		}
	}
	return sum;
}


int main() {
	
	int n, m, r;
	int maxItem=0;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> NumOfItem[i];
	}

	int from, to, cost;
	for (int i = 0; i < r; i++) {
		cin >> from >> to >> cost;
		dijkstraV[from].push_back({ to, cost });
		dijkstraV[to].push_back({ from,cost });
	}

	for (int i = 1; i <= n; i++) {
		distanceV.assign(101, INT_MAX);
		dijkstra(i);
		if(maxItem < getNumOfItem(i, n, m))
			maxItem = getNumOfItem(i, n, m);
	}
	cout << maxItem;
}