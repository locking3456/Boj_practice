#include <iostream>
#include <queue>
using namespace std;
int arr[101];
int visited[101];
int radder[101];
queue<int> bfsq;
int solution() {
	bfsq.push(1);
	while (!bfsq.empty()) {
		int start = bfsq.front();
		bfsq.pop();
		if ((start + 6 <= 100) && !visited[start + 6]) {
			if (radder[start + 6] > 0) {
				if (visited[radder[start + 6]] == 0) {
					visited[radder[start + 6]] = visited[start] + 1;
					bfsq.push(radder[start + 6]);
				}
			}
			else if (radder[start + 6] == 0) {
				visited[start + 6] = visited[start] + 1;
				bfsq.push(start + 6);
			}
			if (start + 6 == 100)
				return visited[start + 6];
		}
		if ((start + 5 <= 100) && !visited[start + 5]) {
			if (radder[start + 5] > 0) {
				if (visited[radder[start + 5]] == 0) {
					visited[radder[start + 5]] = visited[start] + 1;
					bfsq.push(radder[start + 5]);
				}
			}
			else if (radder[start + 5] == 0) {
				visited[start + 5] = visited[start] + 1;
				bfsq.push(start + 5);
			}
			if (start + 5 == 100)
				return visited[start + 5];
		}
		if ((start + 4 <= 100) && !visited[start + 4]) {
			if (radder[start + 4] > 0) {
				if (visited[radder[start + 4]] == 0) {
					visited[radder[start + 4]] = visited[start] + 1;
					bfsq.push(radder[start + 4]);
				}
			}
			else if (radder[start + 4] == 0) {
				visited[start + 4] = visited[start] + 1;
				bfsq.push(start + 4);
			}
			if (start + 4 == 100)
				return visited[start + 4];
		}
		if ((start + 3 <= 100) && !visited[start + 3]) {
			if (radder[start + 3] > 0) {
				if (visited[radder[start + 3]] == 0) {
					visited[radder[start + 3]] = visited[start] + 1;
					bfsq.push(radder[start + 3]);
				}
			}
			else if (radder[start + 3] == 0) {
				visited[start + 3] = visited[start] + 1;
				bfsq.push(start + 3);
			}
			if (start + 3 == 100)
				return visited[start + 3];
		}
		if ((start + 2 <= 100) && !visited[start + 2]) {
			if (radder[start + 2] > 0) {
				if (visited[radder[start + 2]] == 0) {
					visited[radder[start + 2]] = visited[start] + 1;
					bfsq.push(radder[start + 2]);
				}
			}
			else if (radder[start + 2] == 0) {
				visited[start + 2] = visited[start] + 1;
				bfsq.push(start + 2);
			}
			if (start + 2 == 100)
				return visited[start + 2];
		}
		if ((start + 1 <= 100) && !visited[start + 1]) {
			if (radder[start + 1] > 0) {
				if (visited[radder[start + 1]] == 0) {
					visited[radder[start + 1]] = visited[start] + 1;
					bfsq.push(radder[start + 1]);
				}
			}
			else if (radder[start + 1] == 0) {
				visited[start + 1] = visited[start] + 1;
				bfsq.push(start+1);
			}
			if (start + 1 == 100)
				return visited[start + 1];
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N+M; i++) {
		int from, to;
		cin >> from>> to;
		radder[from] = to;
	}

	cout << solution();
}
