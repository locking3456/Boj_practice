#include <iostream>
using namespace std;
int main()
{
	int room,i,x;
	cin >> room;
	i = 1;
	x = 0;
	while (6*x+1 < room){
		x = i + x;
		i++;
	}
	cout << i;
}