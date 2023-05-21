#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int num;
	int point;
	vector<int> inputarray;
	vector<int> inputarray2;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> point;
		inputarray.push_back(point);
		inputarray2.push_back(point);
	}
	sort(inputarray.begin(), inputarray.end());
	inputarray.erase(unique(inputarray.begin(), inputarray.end()), inputarray.end());//중복된 원소를 제거하는 코드
	for (int i = 0; i < num; i++)
	{
		cout << (lower_bound(inputarray.begin(), inputarray.end(), inputarray2[i]) - inputarray.begin())<<" ";
	}

}