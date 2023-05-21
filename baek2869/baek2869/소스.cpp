#include<iostream>
using namespace std;
int main()
{
	int x, y, upmet, downmet, goalpoint;
	x = 0, y = 0;
	cin >> upmet >> downmet >> goalpoint;
	if ((goalpoint - downmet) % (upmet - downmet)>0) {
		cout << (goalpoint - downmet) / (upmet - downmet) + 1;
	}
	else
		cout << (goalpoint - downmet) / (upmet - downmet);
}