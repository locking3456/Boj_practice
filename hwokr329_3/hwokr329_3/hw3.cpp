#include <iostream>
using namespace std;
int factorial(int n)
{
	int z = 1;
	for(int i = 1; i <= n; i++) //z���ٰ� 1���� n������ ���� ��� ��ø�ؼ� �����ؼ� ���� ����
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