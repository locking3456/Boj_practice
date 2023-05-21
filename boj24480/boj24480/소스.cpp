#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vertex[100001];
int visited[100001];
int visitedRank[100001];
int countnum=0;
void dfs(int start) {
	if (visited[start] == false) {
		visited[start] = true;
		countnum += 1;
		visitedRank[start] = countnum;
		int sizeofvertex = vertex[start].size();
		for (int i = 0; i < sizeofvertex; i++) {
			if (visited[vertex[start][i]] == false) {
				dfs(vertex[start][i]);
			}
		}
	}

}
int main() {
	int vertexnum, edgenum, startvertex;
	cin >> vertexnum >> edgenum >> startvertex;
	
	for (int i = 1; i <= edgenum; i++) {
		int temp1,temp2;
		cin >> temp1>>temp2;
		vertex[temp2].push_back(temp1);
		vertex[temp1].push_back(temp2);
	}
	for (int i = 1; i <= vertexnum; i++) {
		sort(vertex[i].rbegin(), vertex[i].rend());
	}
	dfs(startvertex);
	for (int i = 1; i <= vertexnum; i++) {
		cout << visitedRank[i] << '\n';
	}
}