#include <iostream>
#include<algorithm>
using namespace std;
int h, w;
int arr[500];
int main() {
	cin >> h >> w;
	int result = 0;
	for (int i = 0; i < w; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < w - 1; i++) {
		int lmax = 0;
		int rmax = 0;
		for (int j = 0; j < i; j++) {
			if (lmax < arr[j] && arr[j]>arr[i])
				lmax = arr[j];
		}
		for (int j = i + 1; j < w; j++) {
			if (rmax < arr[j] && arr[j]>arr[i])
				rmax = arr[j];
		}
		if (lmax != 0 && rmax != 0)
			result += min(lmax, rmax) - arr[i];
	}
	cout << result;

}