#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
bool visited[100001];
int result[100001];

int N, M, R;
vector <int> dfsv[100001];
int dfs(int start,int cnt) {
	result[start] = cnt;
	visited[start] = true;
	for (int i = 0; i < dfsv[start].size(); i++) {
		if (!visited[dfsv[start][i]]) {
			dfs(dfsv[start][i],cnt+1);	
		}		
	}
	return 0;
}

int main() {
	memset(result, -1, sizeof(int) * 100001);
	scanf("%d %d %d", &N, &M, &R);
	int temp1, temp2;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &temp1, &temp2);
		dfsv[temp1].push_back(temp2);
		dfsv[temp2].push_back(temp1);
	}

	for (int i = 1; i <= N; i++) {
		sort(dfsv[i].begin(), dfsv[i].end());
	}
	dfs(R,0);
	for (int i = 1; i <= N; i++) {
		printf("%d\n", result[i]);
	}
}