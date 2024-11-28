#include <iostream>
#include<queue>
using namespace std;
int n, m;

#define INF 1e9+7
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> djikstra_pq;
vector<pair<int, int>> edgeList[5001];
vector<int> distanceV(5001);
void djikstraSolution(int start) {
	int startNode = start;
	int toCost = 0;
	djikstra_pq.push({ startNode,toCost });

	while (!djikstra_pq.empty()) {
		int toVertex = djikstra_pq.top().first;
		int toCost = djikstra_pq.top().second;

		djikstra_pq.pop();

		int distanceToNextVertex = distanceV[toVertex];
		if (distanceToNextVertex < toCost) {
			continue;
		}
		for (int i = 0; i < edgeList[toVertex].size(); i++) {
			// 다음 인덱스로 가는 cost
			int cost = edgeList[toVertex][i].second + toCost;
			// 나를 통해 갈 다음 IDX
			int nextIdx = edgeList[toVertex][i].first;
			if (cost < distanceV[nextIdx]) {
				distanceV[nextIdx] = cost;
				djikstra_pq.push({ nextIdx,cost });
			}
		}


	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;

		edgeList[temp1].push_back({ temp2,temp3 });
		edgeList[temp2].push_back({ temp1,temp3 });

	}
	int start, end;
	cin >> start >> end;

	distanceV.assign(n + 1, INF);
	djikstraSolution(start);

	cout << distanceV[end];
}