#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, R;
vector<int> bfsv[100001];
bool visited[100001];
int result[100001];
int cnt = 0;
bool compare(int i, int j) {
	return j < i;
}
void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	cnt++;
	result[start] = cnt;
	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		for (int i = 0; i < bfsv[parent].size(); i++) {
			int temp = bfsv[parent][i];
			if (visited[temp] == false) {
				cnt++;
				q.push(temp);
				result[temp] = cnt;
				visited[temp] = true;
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &R);
	int temp1, temp2;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &temp1, &temp2);
		bfsv[temp1].push_back(temp2);
		bfsv[temp2].push_back(temp1);
	}
	for (int i = 1; i <= N; i++) {
		sort(bfsv[i].begin(), bfsv[i].end(),compare);
	}
	bfs(R);

	for (int i = 1; i <= N; i++) {
		printf("%d\n", result[i]);
	}
	
}