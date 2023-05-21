#include <iostream>
#include<string>
int check(int length, const char grwd[]);
using namespace std;
int main()
{
	int i, j, sum;
	sum = 0;
	string grwd;
	cin >> i;
	for (j = 0; j < i; j++)
	{
		cin >> grwd;
		sum += check( grwd.length(),grwd.c_str());
	}
	cout << sum;
}
int check(int length, const char grwd[])
{
	int count,l,k;
	for (k = 0; k < length; k++)
	{
		for (l = 0; l < length; l++)
		{
			if (grwd[k] == grwd[l])
			{
				count = l - k;
				if (count > 1)
				{
					if (grwd[l] != grwd[l-1])
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
} bn
