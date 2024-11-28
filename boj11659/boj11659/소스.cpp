#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
int N;
int M;
int arr[100001] = { 0, };
int i, j;
int main() {

	int temp1, temp2;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		arr[i] = arr[i] + arr[i - 1];
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &temp1, &temp2);
		printf("%d\n", arr[temp2] - arr[temp1 - 1]);
	}
}