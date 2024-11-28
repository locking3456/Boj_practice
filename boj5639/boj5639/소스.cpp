#include <iostream>
using namespace std;

int arr[10005];

void post(int start, int end) {
	if (start >= end) return;
	//else if (start == end-1) {
	//	cout << arr[start] << endl;
	//	return;
	//}
	int i;
	for (i = start + 1; i < end; i++)
		if (arr[start] < arr[i]) 
			break;
	post(start + 1, i);
	post(i , end);
	cout << arr[start] << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num;
	int idx=0;
	//while (true) {
	//	cin >> num;
	//	if (num == 0) {
	//		break;
	//	}
	//	else {
	//		arr[idx] = num;
	//		idx++;
	//	}
	//}
	while (cin >> num) {
		arr[idx] = num;
		idx++;
	}
	post(0, idx);
}