#include <iostream>
using namespace std;
int main()
{
	int stcost, varcost, margin;
	cin >> stcost >> varcost >> margin;
	int y;
	y = 0;
	if (varcost >= margin) {
		cout << -1;
	}
	else {
		while (stcost + varcost * y+1 > margin * y+1){
			y++;
		}
		cout << y+1;
	}
}