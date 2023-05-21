#include <iostream>
using namespace std;
int main
{
	int i,j, k, l,m,cnt,count;
	string grwd[100];
	string alph = "abcdefghijklmnopqrstuvwxyz";
	string vc = " ";
	cin >> i;
	count = 0;
	cnt = 0;
	for (j = 0; j < i; j++)
	{
		cout << "shit";
		cin >> grwd[j];
		for (k = 0; k < 26; k++)
		{
			for (l = 0; l < grwd[j].length(); l++)
				{
					if (alph[k] == grwd[j].at(l))
					{
						grwd[j].replace(j, 1, vc);
					}
					else
					{
						break;
					}

				}

		}
	}
}