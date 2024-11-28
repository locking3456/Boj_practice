#include <iostream>
using namespace std;
int N, M;
int arr[100][100];
int willMelt[100][100];
int xIdx[4] = { 1,0,-1,0 };
int yIdx[4] = { 0,1,0,-1 };
bool isVisited[100][100] = { 0, };
bool canGo(int x, int y) {
	if (x < N && y < M && x >= 0 && y >= 0) {
		if (!isVisited[x][y] && (arr[x][y] == 1))
			return true;
		else
			return false;
	}
	else
		return false;
}
void copyArr(int arr[100][100], int arr2[100][100]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			arr[i][j] = arr2[i][j];
		}
}
void dfs(int x, int y) {
	int zeroCount = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[x + xIdx[i]][y + yIdx[i]] == -1) {
			zeroCount += 1;
		}
		if (canGo(x + xIdx[i], y + yIdx[i])) {
			isVisited[x + xIdx[i]][y + yIdx[i]] = true;
			dfs(x + xIdx[i], y + yIdx[i]);
		}
	}
	if (zeroCount >= 2) {
		willMelt[x][y] = 0;
	}

}
void airDfs(int x, int y) {
	arr[x][y] = -1;
	for (int i = 0; i < 4; i++) {
		if (x + xIdx[i] < N && y + yIdx[i] < M && x + xIdx[i] >= 0 && y + yIdx[i] >= 0 && !isVisited[x + xIdx[i]][y + yIdx[i]]&& (arr[x + xIdx[i]][y + yIdx[i]] == 0|| arr[x + xIdx[i]][y + yIdx[i]] == -1)) {
			isVisited[x + xIdx[i]][y + yIdx[i]] = true;
			arr[x + xIdx[i]][y + yIdx[i]] = -1;
			airDfs(x + xIdx[i], y + yIdx[i]);
		}
	}


}
void meltCheese() {
	copyArr(willMelt, arr);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!canGo(i, j))
				continue;
			isVisited[i][j] = true;
			dfs(i, j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			isVisited[i][j] = false;
		}
	}
	copyArr(arr, willMelt);
}
bool isMelted() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != -1)
				sum += 1;
		}
	}
	if (sum == 0)
		return true;
	else
		return false;
}
void process() {
	int year = 0;
	airDfs(0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			isVisited[i][j] = false;
		}
	}
	while (!isMelted()) {
		meltCheese();
		airDfs(0, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				isVisited[i][j] = false;
			}
		}
		year += 1;
	}
	cout << year;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	process();
}