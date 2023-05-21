#include <iostream>
using namespace std;
int main()
{
	int x, y, z,cmandnum;
	cout << "숫자를 입력하시오: ";
	cin >> x >> y >> z;
	cout << "커맨드를 입력하세요: ";
	cin >> cmandnum;
	if (cmandnum == 1) //command를 입력 받아 조건에 맞는 if문으로 들어가 해당하는 값을 계산함
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