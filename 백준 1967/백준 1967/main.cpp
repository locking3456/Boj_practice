#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;
vector<pair<int, int>> dfsV[10001];
bool isVisited[10001];
int maxlen=0;
int maxnode = 0;
void dfs(int start, int len) {


	isVisited[start] = true;
	if (maxlen < len) {
		maxlen = len;
		maxnode = start;
	}

	
	for (int i = 0; i < dfsV[start].size(); i++) {
		if (isVisited[dfsV[start][i].first] == false) {
			dfs(dfsV[start][i].first, dfsV[start][i].second+len);
		}
		else {
			continue;
		}
	}
}
int main() {
	int n;
	cin >> n;
	int temp1, temp2, temp3;
	for (int i = 1; i < n; i++) {
		cin >> temp1 >> temp2 >> temp3;

		dfsV[temp1].push_back({ temp2,temp3 });
		dfsV[temp2].push_back({ temp1,temp3 });
	}
	dfs(1, 0);
	maxlen = 0;


	memset(isVisited, 0, sizeof(isVisited));
	dfs(maxnode, 0);
	cout << maxlen;


}