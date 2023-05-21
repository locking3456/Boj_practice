#include<cstdio>
#include<deque>
using namespace std;
int main() {
	int* arr;
	deque<int> q;
	int num;
	int j;
	int x;
	int p=0;
	int count = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &j);
		q.push_back(j);
	}
	while (!q.empty())
	{
		count = 0;
		x = q.front();
		q.pop_front();
		if (q.empty()) {
			printf("-1 ");
			continue;
		}

		for (p = 0; p < q.size(); p++) {
			if (x < q[p]) {
				printf("%d ", q[p]);
				count = 0;
				break;
			}
			else
				count = 1;
		}

		if (count == 1)
			printf("-1 ");
	}
}