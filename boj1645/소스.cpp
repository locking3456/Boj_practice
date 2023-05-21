#include <iostream>
using namespace std;
int main()
{
	int k;
	int* arr;
	int essen;
	long long mid;
	int count=0;
	long long low = 1;
	long long max = 0;
	int answer=0;
	cin >> k;
	arr = new int[k];
	cin >> essen;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	while (low <= max)
	{
		count = 0;
		mid = (max + low) / 2;
		for (int i = 0; i < k; i++)
		{
			count += arr[i] / mid;
		}
		if (count <= essen)
		{
			max = mid - 1;
			if (answer < mid)
				answer = mid;
		}
		else if (count > essen)
			low = mid + 1;
	}
	cout << answer;
}