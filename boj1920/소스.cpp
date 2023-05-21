#include <stdio.h>
#include <algorithm>
using namespace std;
int binarysearch(int *a, int answer,int low, int high) {
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
	int* arr;
	int* arr2;
	scanf("%d",&num2);
	arr = new int[num2];
	for (int i = 0; i < num2; i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+num2);
	scanf("%d", &num);
	arr2 = new int[num];
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d\n",binarysearch(arr, arr2[i], 0, num2 - 1));
	}
}