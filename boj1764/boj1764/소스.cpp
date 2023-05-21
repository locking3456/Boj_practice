#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string DeutBo[500000];
string Bodo[500000];
string Answer[500000];
int binarysearch(string* a, string answer, int low, int high) {
	int mid;
	if (low > high)
		return 0;
	else {
		mid = (low + high) / 2;
		if (answer == a[mid]) {
			return 1;
		}
		else if (answer < a[mid]) 
			return binarysearch(a, answer, low, mid - 1);
		else
			return binarysearch(a, answer, mid + 1, high);
		
	}
}
int main() {
	int N, M;
	int cnt=0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> DeutBo[i];
	}
	sort(DeutBo, DeutBo+N);
	for (int i = 0; i < M; i++) {
		cin >> Bodo[i];
	}
	sort(Bodo, Bodo + M);
	for (int i = 0; i < M; i++) {
		if (binarysearch(DeutBo, Bodo[i], 0, M)) {
			Answer[cnt] = Bodo[i];
			cnt++;
		}
	}
	cout << cnt<<'\n';
	for (int i = 0; i < cnt; i++) {
		cout << Answer[i] << '\n';
	}
}