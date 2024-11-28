#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> djikstra_pq;
vector<pair<int, int>> edgeList[100000];
vector<int> distance_v;
int testCase;
int n, d, c;
#define INF 1000000001
void djikstraSolution(int start) {
	int startNode = start;
	int toCost = 0;
	djikstra_pq.push({ toCost,startNode });
	while (!djikstra_pq.empty())
	{
		int vertex = djikstra_pq.top().second;
		int toCost = djikstra_pq.top().first;
		djikstra_pq.pop();
		if (toCost > distance_v[vertex])
			continue;

		for (int i = 0; i < edgeList[vertex].size(); i++) {
			int nextVertex = edgeList[vertex][i].first;
			int nextCost = edgeList[vertex][i].second;
			if (distance_v[nextVertex] > nextCost + toCost) {
				distance_v[nextVertex] = nextCost + toCost;
				djikstra_pq.push({ nextCost + toCost,nextVertex });
			}
		}
	}
}
int main() {
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			edgeList[to].push_back({ from,cost });
		}
		distance_v.assign(n + 1, INF);
		int cpuCnt, lastSecond;
		djikstraSolution(c);
		lastSecond = 0;
		cpuCnt = 0;
		distance_v[c] = 0;
		for (int i = 1; i <= n; i++) {
			if (distance_v[i] != INF) {
				cpuCnt++;
				if (distance_v[i] > lastSecond) {
					lastSecond = distance_v[i];
				}
			}
			edgeList[i].clear();
		}
		cout << cpuCnt << " " << lastSecond << endl;
	}
}