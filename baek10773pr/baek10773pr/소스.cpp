#include <iostream>
#include <stack>
using namespace std;
int main()
{
	//int count,sum,t;
	//int k=0;
	//t = 0;
	//stack<int> s;
	//cin >> count;
	//for (int i = 0; i < count; i++)
	//{
	//	cin >> k;
	//	if (k == 0)
	//	{
	//		s.pop();
	//	}
	//	else
	//	{
	//		s.push(k);
	//	}
	//}
	//sum = s.size();

 //	while(s.empty()!=1)
	//{

	//	t = t + s.top();
	//	break;
	//}
	//cout << t<<endl;
	int K, n;
	cin >> K;

	stack<int> s;
	for (int i = 0; i < K; i++) {
		cin >> n;
		if (n)
			s.push(n);
		else
			s.pop();
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum << endl;
}