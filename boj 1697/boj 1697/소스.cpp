#include <iostream>
#include <queue>
using namespace std;
int visited[200002];
int N, K;

int main() {
	cin >> N >> K;
	queue<int> hs;
	hs.push(N);
	visited[N] = 0;
	while (true) {
		if (hs.front() == K) {
			break;
		}
		if (hs.front() > 0) {
			if (!visited[hs.front() - 1]) {
				hs.push(hs.front() - 1);
				visited[hs.front() - 1] = visited[hs.front()] + 1;
			}
		}
		if (hs.front() < 100000) {
			if (!visited[hs.front() + 1]) {
				hs.push(hs.front() + 1);
				visited[hs.front() + 1] = visited[hs.front()] + 1;
			}
		}
		if (hs.front() <= 50000) {
			if (!visited[hs.front() * 2]) {
				hs.push(hs.front() * 2);
				visited[hs.front() * 2] = visited[hs.front()] + 1;
			}
		}
		hs.pop();
	}
	cout << visited[K];
}