#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;//나무의 수
	long long m;//나무의 길이
	long long* arr;
	long long low=0;
	long long max=0;
	long long mid=0;
	long long ans=0;
	long long result=0;

	cin >> n;
	cin >> m;
	arr = new long long[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld",&arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}
	while (max >= low) {
		ans = 0;
		mid = (max + low) / 2;
		for (int i = 0; i < n; i++)
		{
			if (mid < arr[i])
			{
				ans += arr[i] - mid;
			}
		}
		if (ans >= m) {
			if (result < mid)
				result = mid;
			low= mid + 1;
		}
		else {
			max = mid - 1;
		}

	}
	cout << result;
}
