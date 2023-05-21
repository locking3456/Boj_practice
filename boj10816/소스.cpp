#include <stdio.h>
#include <algorithm>
using namespace std;
int binarysearch(int* a, int answer, int low, int high) {
	int mid;
	if (low > high)
		return 0;
	else {
		mid = (low + high) / 2;
		if (answer == a[mid])
			return 1;
		else if (answer < a[mid])
			return binarysearch(a, answer, low, mid - 1);
		else
			return binarysearch(a, answer, mid + 1, high);
	}
}
int main() {
	int num;
	int num2;
	int x;
	int* arr;
	int* arr3;
	arr3 = new int[20000001]{ 0, };
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++) {
		scanf("%d", &x);
		arr3[x + 10000000] = arr3[x + 10000000] + 1;
	}
	scanf("%d", &num);
	arr = new int[num];
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr3[arr[i] + 10000000]);
	}
}