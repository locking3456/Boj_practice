#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int>vertex[101];
bool visited[101] = { 0, };
int cnt;
void dfs(int start) {
	if (visited[start] == false) {
		visited[start] = true;
		cnt++;
		int sizeofvertex = vertex[start].size();
		for (int i = 0; i < sizeofvertex; i++) {
			if (visited[vertex[start][i]] == false) {
				dfs(vertex[start][i]);
			}
		}
	}
}
int main() {
	int comNum, edgeNum,temp1,temp2;
	cin >> comNum >> edgeNum;
	for (int i = 0; i < edgeNum; i++) {
		cin >> temp1 >> temp2;
		vertex[temp1].push_back(temp2);
		vertex[temp2].push_back(temp1);
	}
	dfs(1);
	cout << cnt-1;
}