#include<iostream>
using namespace std;
int operand[11];
int operators[4];
int level;
int min2=100000001;
int max2 = -100000001;
int result;
 void solve(int n) {
	 int before;
	if (level == n) {
		if (result > max2)
			max2 = result;
		if (result < min2)
			min2 = result;
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++) {
			if (operators[i] > 0 &&i==0)
			{
				before = result;
				result = result + operand[n];
				operators[0]--;
				solve(n + 1);
				operators[0]++;
				result = before;

			}
			else if (operators[i] > 0&&i==1)
			{
				before = result;
				result = result - operand[n];
				operators[1]--;
				solve(n + 1);
				operators[1]++;
				result = before;
			}
			else if (operators[i] > 0&& i == 2)
			{
				before = result;
				result = result * operand[n];
				operators[2]--;
				solve(n + 1);
				operators[2]++;
				result = before;
			}
			else if (operators[i] > 0 && i == 3)
			{
				before = result;
				result = result / operand[n];
				operators[3]--;
				solve(n + 1);
				operators[3]++;
				result = before;
			}
		}
		return;
	}
}
int main() {
	cin >> level;
	for (int i = 0; i < level; i++) {
		cin >> operand[i];
	}
	result = operand[0];
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}
	solve(1);
	cout << max2 << endl;
	cout << min2 << endl;

}