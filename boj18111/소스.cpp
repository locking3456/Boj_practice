#include <iostream>
using namespace std;
int main() {
	int width;
	int height;
	int blnum;
	int block[501][501];//블록의 배열
	int myblock;//내블록의 개수
	int cost;
	int realcost=0;
	int mincost= 2147483647;
	int maxheight=-1;
	cin >> height >> width >> blnum;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> block[i][j];
		}
	}

	for(int i=0; i<=256;i++)
	{
		realcost = 0;
		cost = 0;


		myblock = blnum;
		for (int j = 0; j < height; j++) {
			for (int k = 0; k< width; k++) {
				cost = block[j][k] - i;
				if (cost > 0) {
					myblock+=cost;
					realcost += (2 * cost);
				}
				else if (cost < 0) {
					myblock+=cost;
					realcost -= cost;
				}
			}
		}
		if (myblock < 0) {//블록이 없으면 생략
			continue;
		}
		if (mincost >= realcost) {
			mincost = realcost;
			maxheight = i;
		}
	}
	cout << mincost << " " << maxheight;
}