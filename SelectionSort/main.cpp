#include <iostream>
#include <algorithm>
using namespace std;

void QuickSort(short* a, const int left, const int right)
{
	int i=0; int j=0; int pivot=0;
	if (left < right)
	{
		i = left, j = right + 1,pivot=a[left];
		do {
			do i++; while (a[i] < pivot);
			do j--; while (a[j] > pivot);
			if (i < j)
			{
				swap(a[i],a[j]);
			}
		} while (i < j);
		swap(a[left], a[j]);
		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
}
int main() {
	int num;
	cin >> num;
	short* arr = new short[num];
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	QuickSort(arr, 0, num-1);
	for (int i = 0; i < num; i++)
	{
		cout << arr[i]<<endl;
	}
}