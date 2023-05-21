#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	string x;
	cin >> x;
	int* arr;
	arr = new int[x.length()];
	for (int i = 0; i < x.length(); i++) {
		arr[i] = x[i] - 48;
	}
	sort(arr,arr+x.length(),greater<int>());
	for (int i = 0; i < x.length(); i++) {
		cout << arr[i];
	}
}