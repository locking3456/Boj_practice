#include<iostream>
#include<queue>
using namespace std;
int N;
char arr[100][100];
bool normalVisited[100][100];
bool weakVisited[100][100];
int normalBFS() {
	queue<pair<int, int>> bfsQ;
	char color;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (normalVisited[i][j])
				continue;
			color = arr[i][j];
			normalVisited[i][j]== true;
			bfsQ.push({ i,j });
			count += 1;
			while (!bfsQ.empty()) {
				int x, y;
				x = bfsQ.front().first;
				y = bfsQ.front().second;
				bfsQ.pop();
				if (x-1>=0&&!normalVisited[x - 1][y] && arr[x - 1][y] == color) {
					bfsQ.push({ x - 1,y });
					normalVisited[x - 1][y] = true;
				}
				if (x + 1 < N && !normalVisited[x + 1][y] && arr[x + 1][y] == color) {
					bfsQ.push({ x + 1,y });
					normalVisited[x + 1][y] = true;
				}
				if (y - 1 >= 0 && !normalVisited[x][y-1] && arr[x][y-1] == color) {
					bfsQ.push({ x,y-1 });
					normalVisited[x][y-1] = true;
				}
				if (y + 1 < N && !normalVisited[x][y + 1] && arr[x][y + 1] == color) {
					bfsQ.push({ x,y + 1 });
					normalVisited[x][y + 1] = true;
				}

			}
			
		}
	}
	return count;
}
int WeakBFS() {
	queue<pair<int, int>> bfsQ;
	char color;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (weakVisited[i][j])
				continue;
			color = arr[i][j];
			weakVisited[i][j] == true;
			bfsQ.push({ i,j });
			count += 1;
			while (!bfsQ.empty()) {
				int x, y;
				x = bfsQ.front().first;
				y = bfsQ.front().second;
				bfsQ.pop();
				if (color == 'R' || color=='G') {
					if (x - 1 >= 0 && !weakVisited[x - 1][y] && (arr[x - 1][y] == 'R' || arr[x - 1][y] == 'G')) {
						bfsQ.push({ x - 1,y });
						weakVisited[x - 1][y] = true;
					}
					if (x + 1 < N && !weakVisited[x + 1][y] && (arr[x + 1][y] == 'R' || arr[x + 1][y] == 'G')) {
						bfsQ.push({ x + 1,y });
						weakVisited[x + 1][y] = true;
					}
					if (y - 1 >= 0 && !weakVisited[x][y - 1] && (arr[x][y-1] == 'R' || arr[x][y-1] == 'G')) {
						bfsQ.push({ x,y - 1 });
						weakVisited[x][y - 1] = true;
					}
					if (y + 1 < N && !weakVisited[x][y + 1] && (arr[x][y+1] == 'R' || arr[x][y+1] == 'G')) {
						bfsQ.push({ x,y + 1 });
						weakVisited[x][y + 1] = true;
					}
				}
				else {
					if (x - 1 >= 0 && !weakVisited[x - 1][y] && arr[x - 1][y] == color) {
						bfsQ.push({ x - 1,y });
						weakVisited[x - 1][y] = true;
					}
					if (x + 1 < N && !weakVisited[x + 1][y] && arr[x + 1][y] == color) {
						bfsQ.push({ x + 1,y });
						weakVisited[x + 1][y] = true;
					}
					if (y - 1 >= 0 && !weakVisited[x][y - 1] && arr[x][y - 1] == color) {
						bfsQ.push({ x,y - 1 });
						weakVisited[x][y - 1] = true;
					}
					if (y + 1 < N && !weakVisited[x][y + 1] && arr[x][y + 1] == color) {
						bfsQ.push({ x,y + 1 });
						weakVisited[x][y + 1] = true;
					}
				}

			}

		}
	}
	return count;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cout <<normalBFS()<<" "<< WeakBFS();
}