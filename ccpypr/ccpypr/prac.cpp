#include <iostream>
using namespace std;
void fillLine(int n = 25, char c = '*');
int main()
{
	fillLine();
	fillLine(3,'!');
}
void fillLine(int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		cout << c;
	}
	cout << endl;
}