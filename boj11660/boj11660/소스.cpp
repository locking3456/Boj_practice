#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
int N, M;
int arr[1025][1025];
int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &temp);
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] + temp - arr[i - 1][j - 1];
		}
	}


	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		printf("%d\n", arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1]);
		
	}

}