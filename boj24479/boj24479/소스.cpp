#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vertex[200001];
int visitednum[100001];
bool visited[100001] = { false, };
int countnum = 0;
void dfs(int start) {
	countnum += 1;
	visitednum[start] = countnum;
	visited[start] = 1;
	for (int i = 0; i < vertex[start].size(); i++) {
		if (visited[vertex[start][i]] == true) {
			continue;
		}
		dfs(vertex[start][i]);
	}
}
int main() {
	int vertexnum, edgenum, startvertex;
	cin >> vertexnum >> edgenum >> startvertex;
	for (int i = 1; i <= edgenum; i++) {
		int temp1 = 0;
		int temp2 = 0;
		cin >> temp1 >> temp2;
		vertex[temp1].push_back(temp2);
		vertex[temp2].push_back(temp1);
	}
	for (int i = 1; i <= vertexnum; i++) {
		sort(vertex[i].begin(), vertex[i].end());
	}
	dfs(startvertex);
	for (int i = 1; i <= vertexnum; i++) {
		cout << visitednum[i]<<'\n';
	}

}