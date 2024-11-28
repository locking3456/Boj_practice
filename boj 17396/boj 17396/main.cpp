#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 1234987654321
priority_queue < pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> djikstra_pq;
vector<pair<int, long long>> edgeList[300000];
vector<long long> distanceV(300000);
bool canGo[300000] = { 0, };
int n, m;
void djikstraSolution(int start) {
	int startNode = start;
	int toCost = 0;
	djikstra_pq.push({ toCost,start });

	while (!djikstra_pq.empty()) {
		int toVertex = djikstra_pq.top().second;
		long long toCost = djikstra_pq.top().first;
		djikstra_pq.pop();

		if (distanceV[toVertex] < toCost)
			continue;

		for (int i = 0; i < edgeList[toVertex].size(); i++) {
			int nextVertex = edgeList[toVertex][i].second;
			long long nextCost = edgeList[toVertex][i].first;
			if (distanceV[nextVertex] > toCost + nextCost && (canGo[nextVertex] || nextVertex==n-1)) {
				distanceV[nextVertex] = toCost + nextCost;
				djikstra_pq.push({ toCost + nextCost,nextVertex });
			}
		}

	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> canGo[i];
		canGo[i] = !canGo[i];
	}

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edgeList[from].push_back({ cost,to });
		edgeList[to].push_back({ cost,from });
	}
	distanceV.assign(n , INF);
	djikstraSolution(0);
	if (distanceV[n - 1] >= INF)
		cout << -1;
	else
		cout << distanceV[n-1];
}