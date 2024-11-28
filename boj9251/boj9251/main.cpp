#include <iostream>
#include <cstring>
using namespace std;
#define max(a, b) (a > b ? a : b)

int LCS[1002][1002];
char str[1003];
char str2[1003];

int main()
{
	cin >> str >> str2;
	int i, j;
	i = 1;
	while (i <= strlen(str))
	{
		j = 1;
		while (j <= strlen(str2))
		{
			if (str2[j - 1] == str[i - 1])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else
			{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
			j++;
		}
		i++;
	}
	printf("%d", LCS[i - 1][j - 1]);
}