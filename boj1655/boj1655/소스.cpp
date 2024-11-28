#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,less<int>> maxq;
priority_queue<int, vector<int>, greater<int>> minq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int inputNum;
	cin >> inputNum;
	maxq.push(inputNum);
	cout << maxq.top() << '\n';
	for (int i = 1; i < N; i++) {
		cin >> inputNum;
		if (maxq.size() == minq.size())
			maxq.push(inputNum);
		else {
			minq.push(inputNum);
		}
		if (!maxq.empty() && !minq.empty() && !(maxq.top() < minq.top())) {
			int a = maxq.top();
			int b = minq.top();

			maxq.pop();
			minq.pop();

			minq.push(a);
			maxq.push(b);
		}
		cout << maxq.top()<<'\n';
	}
}