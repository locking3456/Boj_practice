#include <iostream>
using namespace std;
int rCubeSum(int n)
{
	if (n < 1)
	{
		return 0;
	}
	else
	{
		return n * n * n + rCubeSum(n - 1); //recursive call�� ���� ��ȯ�Լ��� �ۼ� return���� �Լ� �ڱ��ڽ��� ���� ������ �����μ� ���ǿ� �����ϸ� Ż��
	}
}
int main()
{
	int x;
	cin >> x;
	cout<<rCubeSum(x);

}