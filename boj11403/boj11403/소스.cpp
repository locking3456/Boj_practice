#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N;
int arr[100][100];
int ans[100][100];
void solution(int vertex) {
	queue<pair<int, int>> bfsq;
	for (int i = 0; i < N; i++) {
		if (arr[vertex][i] == 1) {
			bfsq.push({ vertex, i });
			ans[vertex][i] = 1;
			while (!bfsq.empty()) {
				int start = bfsq.front().first;
				int end = bfsq.front().second;
				bfsq.pop();
				for (int j = 0; j < N; j++) {
					if (arr[end][j] == 1 &&ans[vertex][j]==0) {
						bfsq.push({ end,j });
						ans[vertex][j] = 1;
					}
				}
				
			}
		}
		
	}

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		solution(i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j]<<" ";
		}
		cout << endl;
	}
}