#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>
#define INT_MAX 987654321
using namespace std;
int N, E;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>>> djikstra_pq;
vector<pair<int, int>> djikstra_v[801];
vector<int> distanceV(801);
void djikstra(int i) {
	int start = i;
	int toCost = 0;
	djikstra_pq.push({ toCost,start });
	distanceV[start] = 0;
	while (!djikstra_pq.empty()) {
		int toCost = djikstra_pq.top().first;
		int toVertex = djikstra_pq.top().second;
		
		djikstra_pq.pop();
		int distanceToNextVertex = distanceV[toVertex];
		if (distanceToNextVertex < toCost) {
			continue;
		}
		for (int i = 0; i < djikstra_v[toVertex].size(); i++) {
			int cost = djikstra_v[toVertex][i].first + toCost;
			int nextIdx = djikstra_v[toVertex][i].second;
			if (cost < distanceV[nextIdx]) {
				distanceV[nextIdx] = cost;
				djikstra_pq.push({ cost,nextIdx });
			}
		}
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		djikstra_v[a].push_back({ c,b });
		djikstra_v[b].push_back({ c,a });
	}
	int v1, v2;
	cin >> v1 >> v2;
	int sToV1, sToV2, v1ToV2, v1ToN, v2ToN;
	distanceV.assign(N+1, INT_MAX);
	djikstra(1);
	sToV1 = distanceV[v1];
	sToV2 = distanceV[v2];
	distanceV.assign(N+1, INT_MAX);
	djikstra(v1);
	v1ToV2 = distanceV[v2];
	v1ToN = distanceV[N];
	distanceV.assign(N+1, INT_MAX);
	djikstra(v2);
	v2ToN = distanceV[N];

	int ans = INT_MAX;

	ans = min(ans, sToV1 + v1ToV2 + v2ToN);
	ans = min(ans, sToV2 + v1ToV2 + v1ToN);

	if ((v1ToV2 == INT_MAX)||ans==INT_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}