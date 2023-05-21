#include<iostream>
#include<string>
using namespace::std;
int main()
{
	cout << "hellow world!";
	int j = 0;
	for (int i = 1; i < 11; i++)
	{
		j = j + i;
	}
	cout << "sum 1 to 10 is " << j << endl;
	for (int i = 65; i < 91; i++)
	{
		cout << "ascii of alphabet" << char(i) << endl;

	}
	for (int i = 65; i < 91; i++)
	{
		cout << "ascii of alphabet" << char(i+32) << endl;
	}
	string univer = "hongik university";
	for (int i = 0; i < univer.size(); i++)
	{
		if (univer.at(i) == ' ')
		{
			cout << " ";
		}
		cout << char(univer.at(i) - 32);
	}
	cout << univer;
}