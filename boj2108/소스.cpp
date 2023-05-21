#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int num;
	float avr=0;
	int max;
	int unmax;
	cin >> num;
	vector<int> arra1;
	int* arr;
	arr = new int[8001]{ 0, };

	for (int i = 0; i < num; i++) {
		int price;
		cin >> price;
		arra1.push_back(price);
		avr = avr + price;
		arr[price+4000] = arr[price+4000] + 1;
	}
	sort(arra1.begin(), arra1.end());
	max = 0;
	int count = 0;
	for (int i = 0; i < 8001; i++) {
		if (arr[i] > max)
		{
			max = arr[i];
			unmax = i;
		}
		
	}
	for (int i = unmax + 1; i < 8001; i++)
	{
		if (arr[i] == max)
		{
			unmax = i;
			break;
		}
	}
	cout << floor((avr/num)+0.5) << endl;
	cout << arra1[(num) / 2 ]<<endl;
	cout << unmax-4000<<endl;
	cout << arra1[num-1] - arra1[0]<<endl;
}