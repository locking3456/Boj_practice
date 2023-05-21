#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int tomato[103][103][103] = { };
int visited[103][103][103];
int arr[3];
queue<tuple<int,int,int>> bfsqueue;
int M, N, K;
int solution() {
	int max = 0;
	for (int a = 1; a <= K; a++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (max < visited[a][i][j]) {
					max = visited[a][i][j] - 1;
				}
				if (visited[a][i][j] == 0) {
					max = -1;
					return max;
				}
			}
		}
	}
	return max;
}
int main() {
	int startX, startY, startZ, temp1;
	cin>> M >> N >> K;
	for (int a = 0; a <= K + 2; a++) {
		for (int i = 0; i <= N + 2; i++) {
			for (int j = 0; j <= M + 2; j++) {
				tomato[a][i][j] = -1;
			}
		}
	}

	for (int a = 1; a <= K; a++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> tomato[a][i][j];
				visited[a][i][j] = tomato[a][i][j];
				if (visited[a][i][j] == 1) {
					bfsqueue.push(make_tuple(a, i, j));
				}
			}
		}
	}

	while (!bfsqueue.empty()) {
		startX = get<1>(bfsqueue.front());
		startY = get<2>(bfsqueue.front());
		startZ = get<0>(bfsqueue.front());
		bfsqueue.pop();
		if (tomato[startZ][startX][startY + 1] == 0 && visited[startZ][startX][startY + 1] == 0) {
			visited[startZ][startX][startY + 1] = visited[startZ][startX][startY] + 1;
			bfsqueue.push(make_tuple(startZ, startX, startY + 1));
		}
		if (tomato[startZ][startX][startY -1] == 0 && visited[startZ][startX][startY - 1] == 0) {
			visited[startZ][startX][startY - 1] = visited[startZ][startX][startY] + 1;
			bfsqueue.push(make_tuple(startZ, startX, startY - 1));
		}
		if (tomato[startZ][startX+1][startY ] == 0 && visited[startZ][startX+1][startY] == 0) {
			visited[startZ][startX+1][startY] = visited[startZ][startX][startY] + 1;
			bfsqueue.push(make_tuple(startZ, startX+1, startY));
		}
		if (tomato[startZ][startX-1][startY] == 0 && visited[startZ][startX-1][startY] == 0) {
			visited[startZ][startX-1][startY] = visited[startZ][startX][startY]+1;
			bfsqueue.push(make_tuple(startZ, startX-1, startY));
		}
		if (tomato[startZ+1][startX][startY] == 0 && visited[startZ+1][startX][startY] == 0) {
			visited[startZ+1][startX][startY] = visited[startZ][startX][startY] + 1;
			bfsqueue.push(make_tuple(startZ+1, startX, startY));

		}
		if (tomato[startZ-1][startX][startY] == 0 && visited[startZ-1][startX][startY] == 0) {
			visited[startZ-1][startX][startY] = visited[startZ][startX][startY] + 1;
			bfsqueue.push(make_tuple(startZ-1, startX, startY));
		}

	}

	cout << solution();
}