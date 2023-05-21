#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N; //공유기의 집개수
	int* arr;
	int C; //공유기 개수
	int count;
	int idxforr;
	int preidx;
	cin >> N >> C;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int right;
	int left;
	int mid;
	idxforr = N - 1;
	right = arr[idxforr];
	left = arr[0];
	while (left <= right)
	{
		preidx = 0;
		count = 1;
		mid = (right+left) / 2;
		for (int i = 0; i < N; i++) {
			if ((arr[i]-arr[preidx]) >=mid) {
				count = count + 1;
				preidx = i;
			}
		}
		if (count >= C) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << right;
}
