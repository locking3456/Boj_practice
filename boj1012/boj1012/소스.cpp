#include <iostream>
#include <queue>
using namespace std;
bool cabbage[52][52];
int visited[52][52];
int main() {
	int T; //�׽�Ʈ ���̽��� ����
	int M, N, K;//M:���α��� N:���α��� K: ���߰� �ɾ����ִ� ��ġ�� ����;'
	cin >> T;
	queue<pair<int, int>> bfsQueue;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cabbage[j][k] = 0;
				visited[j][k] = 0;
			}
		}
		for (int j = 0; j < K; j++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
			cabbage[temp1][temp2] = 1;
		}
		int countnum = 0;
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (visited[j][k] == 1 && cabbage[j][k]==1)
					continue;
				else if(visited[j][k]==0 && cabbage[j][k]==1){
					countnum += 1;
					cabbage[j][k] = 1;
					bfsQueue.push(pair<int, int>(j, k));
					while (!bfsQueue.empty()) {
						int firstn,secondn;
						firstn = bfsQueue.front().first;
						secondn = bfsQueue.front().second;
						bfsQueue.pop();
						if (firstn >= 1) {
							if (visited[firstn - 1][secondn]==0 &&cabbage[firstn-1][secondn] == 1) {
								bfsQueue.push(pair<int, int>(firstn - 1, secondn));
								visited[firstn - 1][secondn] = 1;
							}
						}
						if (secondn >= 1) {
							if (visited[firstn][secondn - 1] == 0 && cabbage[firstn][secondn - 1]==1) {
								bfsQueue.push(pair<int, int>(firstn, secondn - 1));
								visited[firstn][secondn - 1] = 1;
							}
						}
						if (visited[firstn + 1][secondn] == 0 && cabbage[firstn + 1][secondn]==1) {
							bfsQueue.push(pair<int, int>(firstn + 1, secondn));
							visited[firstn + 1][secondn] = 1;
						}
						if (visited[firstn ][secondn+1] == 0 && cabbage[firstn][secondn + 1]==1) {
							bfsQueue.push(pair<int, int>(firstn , secondn+1));
							visited[firstn][secondn + 1] = 1;
						}
					}
				}
			}
			
		}
		cout << countnum << '\n';
	}
}