#include <iostream>
#include <queue>
#include <stack>
#define INT_MAX 2147483647
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>  pq;
vector<pair<int, int>> djikstraV[1001];
vector<int>distanceV;
int * arr;
stack<int> RouteStack;
int n, m;
void djikstraF(int start,int target) {
	pq.push({ 0,start });
	
	while (!pq.empty()) {
		int to = pq.top().second;
		int costTo = pq.top().first;
		pq.pop();

		if (to == target)
			return;

		for (int i = 0; i<djikstraV[to].size(); i++) {
			int cost = costTo + djikstraV[to][i].first;
			if (cost < distanceV[djikstraV[to][i].second]) {
				distanceV[djikstraV[to][i].second] = cost;
				arr[djikstraV[to][i].second] = to;
				pq.push({ cost,djikstraV[to][i].second });
			}
		}
	}

}
int main() {
	cin >> n >> m;
	int x, y;
	distanceV = vector<int>(n+1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		//z는 비용 //y는 도착지
		cin >> x >> y >> z;
		djikstraV[x].push_back({ z,y });
	}
	for (int i = 0; i <= n; i++) {
		distanceV[i] = INT_MAX;
	}
	distanceV[1] = 0;
	arr = new int[n+1];
	cin >> x >> y;
	djikstraF(x,y);
	int start = y;
	while (start!=0) {
		RouteStack.push(start);
		if (start == 1)
			break;
		start = arr[start];

	}
	cout << distanceV[y] << endl;
	cout << RouteStack.size() << endl;
	while (!RouteStack.empty()) {
		cout << RouteStack.top()<<" ";
		RouteStack.pop();
	}
}