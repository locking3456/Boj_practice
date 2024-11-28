#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> djikstra_pq;
vector<int> distanceV(50001);
vector<pair<int, int>> cowData[50001];
int n, m;
void djikstra(int start) {
	djikstra_pq.push({ 0,start });
	distanceV[start] = 0;

	while (!djikstra_pq.empty()) {
		int costTo = djikstra_pq.top().first;
		int toIdx = djikstra_pq.top().second;
		djikstra_pq.pop();

		if (distanceV[toIdx] < costTo)
			continue;
		for (int i = 0; i < cowData[toIdx].size(); i++) {
			int nextCost = cowData[toIdx][i].first;
			int nextVertex = cowData[toIdx][i].second;
			if (distanceV[nextVertex] > nextCost + costTo) {
				distanceV[nextVertex] = nextCost + costTo;
				djikstra_pq.push({nextCost+costTo,nextVertex});
			}
		}
	}
}
int main() {
	cin >> n >> m;
	int from, to, cost;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		cowData[from].push_back({ cost,to });
		cowData[to].push_back({ cost,from });
	}
	distanceV.assign(50001, INF);
	djikstra(1);
	cout << distanceV[n];
}