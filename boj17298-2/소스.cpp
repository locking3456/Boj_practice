#include <cstdio>
#include <stack>
using namespace std;
int main()
{
	stack<int>s;
	stack<int>answer;
	stack<int>k;
	int num;
	int val;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &val);
		s.push(val);
	}

	for (int i = 0; i < num; i++) {
		if (k.empty()) {//k�� ����ִٴ� ���� ���� ����
			answer.push(-1);
			k.push(s.top());
			s.pop();
			continue;
		}
		if (k.top() > s.top())
		{
			answer.push(k.top());
			k.push(s.top());
			s.pop();
			continue;
		}

		while (k.top() <= s.top())
		{
			k.pop();
			if (k.empty()) {
				answer.push(-1);
				k.push(s.top());
				s.pop();
				break;
			}
			if (k.top() > s.top())
			{
				answer.push(k.top());
				k.push(s.top());
				s.pop();
				break;
			}
		}
	}
	while (!answer.empty())
	{
		printf("%d ", answer.top());
		answer.pop();
	}

}