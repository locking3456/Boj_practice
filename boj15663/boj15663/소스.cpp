#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int beforearr[8] = { 0, };
int arr[8];
int answer[8];
bool isused[8];
int cnt;
void solution(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i]<<" ";
		}
		cout << endl;
		return;
	}
	int finalusing = 0;
	for (int i = 0; i < N; i++) {
		if (!isused[i] && (finalusing!=arr[i])){
			answer[level] = arr[i];
			finalusing = answer[level];
			isused[i] = true;
			solution(level + 1);
			isused[i] = false;
		}
	}

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	solution(0);
}