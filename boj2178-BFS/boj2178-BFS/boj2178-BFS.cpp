#include <iostream>
#include <utility>
#include <queue>
using namespace std;
char maze[101][101] = { '0', };
int visited[101][101] = { 0, };//각 정점의 단계수를 표시하기 위함
int N = 0, M = 0;
queue<pair<int, int>>visitedqueue;
int main() {
	int startx = 0, starty = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
	}
	startx = 0;
	starty = 0;
	visited[0][0] = 1;
	visitedqueue.push({ startx, starty });
	while (!visitedqueue.empty()) {
		startx = visitedqueue.front().first;
		starty = visitedqueue.front().second;
		visitedqueue.pop();
		
		if (maze[startx][starty + 1] == '1' && visited[startx][starty + 1] == false) {
			visitedqueue.push({ startx,starty + 1 });	
			visited[startx][starty + 1] = 1 + visited[startx][starty];
		}
		if (maze[startx + 1][starty] == '1' && visited[startx + 1][starty] == false) {
			visitedqueue.push({ startx+1,starty });
			visited[startx+1][starty] = 1 + visited[startx][starty];
		}
		if (maze[startx - 1][starty] == '1' && visited[startx - 1][starty] == false) {
			visitedqueue.push({ startx-1,starty });
			visited[startx-1][starty] = 1 + visited[startx][starty];
		}
		if (maze[startx][starty - 1] == '1' && visited[startx][starty - 1] == false) {
			visitedqueue.push({ startx,starty-1 });
			visited[startx][starty - 1] = 1 +visited[startx][starty];
		}
		

	}

	cout << visited[N - 1][M - 1];

}