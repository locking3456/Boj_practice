#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;
vector <int> vertex[10002];
vector <int> resultofDfs;
vector <int> resultofBfs;
int vertexnum;
bool visited[1001] = { false, };

//dfs 함수
void dfs(int start) {
	resultofDfs.push_back(start);
	visited[start] = 1;
	for (int i = 0; i < vertex[start].size(); i++) {
		if (visited[vertex[start][i]] == true){
			continue;
		}
		dfs(vertex[start][i]);
	}
}
int main() {

	queue<int> Bfsqueue;
	int edgenum;
	int startvertex;
	int startvertexforDfs;
	int inputvertex;
	int inputedge;
	cin >> vertexnum;
	cin >> edgenum;
	cin >> startvertex;
	startvertexforDfs = startvertex;


	resultofBfs.push_back(startvertex);
	for (int i = 0; i < edgenum; i++) {
		cin >> inputvertex >> inputedge;
		vertex[inputvertex].push_back(inputedge);
		vertex[inputedge].push_back(inputvertex);
	}
	//작은것부터 나와야하니까 정렬해준다
	for (int i = 1; i <= edgenum; i++) {
		sort(vertex[i].begin(), vertex[i].end());
	}
	//DFS
	dfs(startvertexforDfs);
	for (int i = 0; i < resultofDfs.size(); i++) {
		cout << resultofDfs[i] << ' ';
	}
	cout << endl;
	// 배열 재사용 위해 초기화
	memset(visited, 0, sizeof(visited));
	//BFS 
	visited[startvertex] = true;
	for (int i = 0; i < vertexnum; i++) {
		int sizeofvertex = vertex[startvertex].size();
		for (int j = 0; j < sizeofvertex; j++) {
			if (visited[vertex[startvertex][j]] == false) {
				visited[vertex[startvertex][j]] = true;
				Bfsqueue.push(vertex[startvertex][j]);
				resultofBfs.push_back(vertex[startvertex][j]);
			}
		}
		if (Bfsqueue.empty()) {
			break;
		}
		startvertex = Bfsqueue.front();
		Bfsqueue.pop();
	}
	for (int i = 0; i < resultofBfs.size(); i++) {
		cout << resultofBfs[i] << ' ';
	}
}