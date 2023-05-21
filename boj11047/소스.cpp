#include <iostream>
using namespace std;
int main() {
	int arr[10];
	int n;
	int money;
	int count1=0;

	cin >> n >> money;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (money / arr[i] > 0) {
			count1 += money / arr[i];
			money %= arr[i];
		}
	}
	cout << count1;

}