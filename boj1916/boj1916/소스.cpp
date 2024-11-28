#include<iostream>
#include<queue>
#include<vector>
#define INT_MAX 2147483647
using namespace std;
vector<pair<int, int>> djikstraPQ [1001];
vector <int> distanceV(1001);
void dijkstra(int start) {
	priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> pq;// front는 cost second 는 index
	pq.push({ 0, start });
	distanceV[start] = 0;
	
	while (!pq.empty()) {
		int costTo = pq.top().first;
		int toIdx = pq.top().second;
		pq.pop();

		if (distanceV[toIdx] < costTo) {
			continue;
		}

		for (int i = 0; i < (int)djikstraPQ[toIdx].size(); i++) {
			// 나랑 연결되어 있는애가 Second 비용이 front
			int cost = djikstraPQ[toIdx][i].second + costTo;
			if (cost < distanceV[djikstraPQ[toIdx][i].first]) {
				distanceV[djikstraPQ[toIdx][i].first] = cost;
				pq.push({ cost, djikstraPQ[toIdx][i].first });
			}
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, start, arrive;
	cin >> N >> M;
	int from, to, cost;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		djikstraPQ[from].push_back({ to,cost });
	}
	cin >> start >> arrive;
	distanceV.assign(1001,INT_MAX);
	dijkstra(start);

	cout << distanceV[arrive];
}