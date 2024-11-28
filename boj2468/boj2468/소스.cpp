#include <iostream>
using namespace std;
int arr[100][100];
bool isVisited[100][100] = { false, };
int maxHeight=0;
int nowHeight;
int N;
void solution(int x, int y) {
	if (isVisited[x][y] == true || arr[x][y]<=nowHeight) {
		return;
	}
	isVisited[x][y] = true;
	if(x+1<N)
		solution(x + 1, y);
	if(x-1>=0)
		solution(x - 1, y);
	if(y-1>=0)
		solution(x, y - 1);
	if(y+1<N)
		solution(x, y + 1);
	return;
}
int main() {
	int topRegion=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > maxHeight) {
				maxHeight = arr[i][j];
			}
		}
	}

	for (int k = 0; k < maxHeight; k++) {
		nowHeight = k;
		
		int tempRegion = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (isVisited[i][j] == false && arr[i][j] >nowHeight) {
					solution(i, j);
					tempRegion++;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				isVisited[i][j] = false;
			}
		}
		if (tempRegion > topRegion)
			topRegion = tempRegion;
	}
	cout << topRegion;
}