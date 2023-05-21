#include <iostream>
using namespace std;
int factorial(int n)
{
	int z = 1;
	for(int i = 1; i <= n; i++) //z에다가 1부터 n까지의 곱을 계속 중첩해서 저장해서 값을 구함
	{
		z = z * i;
	}
	return z;
}
int main()
{
	int k;
	cin >> k;
	cout<<factorial(k);
}