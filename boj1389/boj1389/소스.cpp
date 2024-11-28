#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
vector<int> bfsv[101];
int arr[101] = { 0, };
int main() {
	queue<pair<int, int>> bfsq;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		bfsv[temp1].push_back(temp2);
		bfsv[temp2].push_back(temp1);
	}
	for (int i = 1; i <= N; i++) {
		int start = i;
		bfsq.push({ start,0 });
		bool isVisited[101] = { 0, };
		while (!bfsq.empty()) {
			int front = bfsq.front().first;
			int second = bfsq.front().second;
			arr[front] += second;
			isVisited[front] = true;
			bfsq.pop();
			for (int j = 0; j < bfsv[front].size(); j++) {
				if (!isVisited[bfsv[front][j]]) {
					bfsq.push({ bfsv[front][j], second + 1 });
					isVisited[bfsv[front][j]] = true;
				}
			}
		}
	}
	int min=5001;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (min > arr[i]) {
			ans = i;
			min = arr[i];
		}
	}
	cout << ans;
}                         