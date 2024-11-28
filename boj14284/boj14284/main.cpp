#include <iostream>
#include <queue>
using namespace std;
int n, m;
int s, t;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> djikstra_pq;
vector<int> distance_v(5001);
vector <pair<int ,long long>> edgeList[5001];
#define INF 200000000
void djikstraSolution(int start) {
	int startNode = start;
	long long toCost = 0;
	djikstra_pq.push({ toCost, startNode });

	while (!djikstra_pq.empty()) {
		int toVertex = djikstra_pq.top().second;
		long long toCost = djikstra_pq.top().first;
		djikstra_pq.pop();
		if (toCost > distance_v[toVertex])
			continue;

		for (int i = 0; i < edgeList[toVertex].size(); i++) {
			int nextVertex = edgeList[toVertex][i].first;
			int nextCost = edgeList[toVertex][i].second;
			if (distance_v[nextVertex] > toCost + nextCost) {
				distance_v[nextVertex] = toCost + nextCost;
				djikstra_pq.push({ toCost + nextCost,nextVertex });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edgeList[from].push_back({ to,cost });
		edgeList[to].push_back({ from,cost });
	}
	distance_v.assign(n+1, INF);
	cin >> s >> t;
	djikstraSolution(s);
	cout << distance_v[t];
}	