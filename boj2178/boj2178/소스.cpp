#include <iostream>
#include <utility>
#include <stack>
using namespace std;
char maze[101][101] = { '0',};
bool visited[100][100] = { false, };
int N = 0, M = 0;
int minnum = 10001;
stack<pair<int, int>> visitedvertex;
void dfs(int startx, int starty) {
	visited[startx][starty] = true;
	visitedvertex.push({ startx,starty });
	if (startx == N-1 && starty == M - 1) {
		if (visitedvertex.size() < minnum) {
			minnum = visitedvertex.size();
		}
	
	}

	else{
		if (maze[startx][starty + 1] == '1' && visited[startx][starty + 1] == false) {
			starty += 1;
			dfs(startx, starty);
			starty -= 1;
			
		}
		if (maze[startx + 1][starty] == '1' && visited[startx + 1][starty] == false) {
			startx += 1;
			dfs(startx, starty);
			startx -= 1;
			
		}
		if (maze[startx - 1][starty] == '1' && visited[startx - 1][starty] == false) {
			startx -= 1;
			dfs(startx, starty);
			startx += 1;
		
		}
		if (maze[startx][starty - 1] == '1' && visited[startx][starty - 1] == false) {
			starty -= 1;
			dfs(startx, starty);
			starty += 1;
		}	
	}
	visited[startx][starty] = false;
	visitedvertex.pop();
}
int main() {
	int startx = 0, starty = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i ++) {
		cin >> maze[i];
	}
	dfs(0, 0);
	cout << minnum;

}