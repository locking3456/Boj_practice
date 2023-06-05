#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
char arr[16];
char answer[16];
int cnta;
int cntj;
bool isPassword;
int solution(int level, int beforeindex) {
	if (level == N) {
		cnta = 0;
		cntj = 0;
		isPassword = false;
		for (int i = 0; i < N; i++) {
			if (answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' || answer[i] == 'o' || answer[i] == 'u')
			{
				cnta++;
			}
			else
				cntj++;
			if (cnta > 0 && cntj > 1) {
				isPassword = true;
				break;
			}
		}
		if (isPassword) {
			for (int i = 0; i < N; i++) {
				cout << answer[i];
			}
			cout << endl;
		}
	}
	else {
		for (int i = beforeindex + 1; i <= M; i++) {
			answer[level] = arr[i];
			solution(level + 1, i);
		}
	}
	return 0;

}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}
	sort(arr+1,arr+M+1);
	solution(0, 0);

}
