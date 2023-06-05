#include <iostream>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	if (K >= N) {
		cout << 0;
	}
	else {
		while (true) {
			int temp = N;
			int cnt = 0;
			while (temp > 0) {
				if (temp % 2 == 0) {
					temp /= 2;
				}
				else {
					temp /= 2;
					cnt++;
				}
			}
			if (K >= cnt)
				break;
			N++;
		}
	}
	cout<<

}