#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	priority_queue<int> plusNum;
	priority_queue<int,vector<int>, greater<int>> negativeNum;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp1;
		cin >> temp1;
		if (temp1 > 0) {
			plusNum.push(temp1);
		}
		else {
			negativeNum.push(temp1);
		}
	}
	int sum = 0;
	while (!plusNum.empty())
	{
		int num1, num2;
		num1 = plusNum.top();
		plusNum.pop();
		if (plusNum.empty()) {
			sum += num1;
			break;
		}
		num2 = plusNum.top();
		plusNum.pop();

		if (num1 != 1 && num2 != 1) {
			sum += num1 * num2;
		}
		else {
			sum += num1 + num2;
		}
	}
	while (!negativeNum.empty())
	{
		int num1, num2;
		num1 = negativeNum.top();
		negativeNum.pop();
		if (negativeNum.empty()) {
			sum += num1;
			break;
		}
		num2 = negativeNum.top();
		negativeNum.pop();
		sum += num1 * num2;

	}

	cout << sum;

}