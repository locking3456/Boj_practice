#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b)) {
			return true;
		}
		else if (abs(a) == abs(b)) {
			if (a > b)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

int main() {
	priority_queue<int,vector<int>,cmp> pq;
	int N,modeN;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> modeN;
		switch (modeN) 
		{
		case 0:
			if (!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			else
				cout << 0 << endl;;
			break;
		default:
			pq.push(modeN);
		}
	}
}