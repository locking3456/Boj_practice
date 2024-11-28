#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int arr[1002][1002] = { 0,};
int answer[1002][1002] = {0,};
int startX, startY;
queue <pair<int,int>> bfsq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int temp;
			cin >> temp;
			arr[i][j] = temp;
			if (temp == 2) {
				startX = i;
				startY = j;
			}
		}
	}
	bfsq.push(make_pair(startX, startY));
	answer[startX][startY] = 0;
	while (!bfsq.empty()) {
		startX = bfsq.front().first;
		startY = bfsq.front().second;
		bfsq.pop();
		if (arr[startX][startY + 1] == 1 && answer[startX][startY + 1] == 0) {
			bfsq.push(make_pair(startX, startY + 1));
			answer[startX][ startY + 1] = 1 + answer[startX][startY];
		}
		if (arr[startX][startY-1] == 1 && answer[startX][startY - 1] == 0) {
			bfsq.push(make_pair(startX, startY - 1));
			answer[startX][startY - 1] = 1 + answer[startX][startY];
		}
		if (arr[startX+1][startY] == 1 && answer[startX+1][startY] == 0) {
			bfsq.push(make_pair(startX+1, startY));
			answer[startX+1][startY] = 1 + answer[startX][startY];
		}
		if (arr[startX-1][startY ] == 1 && answer[startX-1][startY] == 0) {
			bfsq.push(make_pair(startX-1, startY));
			answer[startX-1][startY] = 1 + answer[startX][startY];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (answer[i][j] == 0&& arr[i][j] == 1) {
				cout << -1 << " ";
			}
			else {
				cout << answer[i][j] << " ";
			}
		}
		cout << endl;
	}
}