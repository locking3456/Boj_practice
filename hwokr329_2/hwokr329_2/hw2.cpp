#include <iostream>
using namespace std;
int main()
{
	int x, y, z,cmandnum;
	cout << "���ڸ� �Է��Ͻÿ�: ";
	cin >> x >> y >> z;
	cout << "Ŀ�ǵ带 �Է��ϼ���: ";
	cin >> cmandnum;
	if (cmandnum == 1) //command�� �Է� �޾� ���ǿ� �´� if������ �� �ش��ϴ� ���� �����
	{
		cout << x + y + z / 3;
	}
	else if (cmandnum == 2)
	{
		cout << x + y + z;
	}
	else if (cmandnum == 3) 
	{

		if (x < y)
		{
			x = y;
		}
		if (x < z)
		{
			x = z;
		}
		cout << x;
	}
	else if (cmandnum == 4)
	{
		if (x > y)
		{
			x = y;
		}
		if (x > z)
		{
			x = z;
		}
		cout << x;
	}
}