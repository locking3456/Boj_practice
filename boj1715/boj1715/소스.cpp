#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
	int card;
	int n;
	int sum = 0;
	cin >> card;
	for (int i = 0; i < card; i++) {
		cin >> n;
		pq.push(n);
	}

	while (pq.size() > 1) {
		int x, y;
		x = pq.top();
		pq.pop();
		y = pq.top();
		pq.pop();
		sum += (x + y);
		pq.push(x + y);
	}
	
	cout << sum;

}