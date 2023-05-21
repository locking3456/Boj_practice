//#include <iostream>
//using namespace std;
//int main() {
//	int tc;
//	int fibon;
//	int fibonacci[41];
//	int fnum0=0;
//	int fnum1=0;
//	cin >> tc;
//	fibonacci[0] = 0;
//	fibonacci[1] = 1;
//	for (int i = 0; i < tc; i++) {
//		cin >> fibon;
//		for (int j = 0; j < fibon; j++) {
//			fibonacci[j+1]=
//		}
//	}
//}

#include<iostream>
using namespace std;
class fs {
public:
	int x;
	int y;
};
int main() {
	fs list[41];
	list[0].x = 1;
	list[0].y = 0;
	list[1].x = 0;
	list[1].y = 1;
	int tc;
	int fnum;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> fnum;
		if (fnum < 2)
			cout << list[fnum].x << " " << list[fnum].y<<endl;
		else {
			for (int j = 2; j <= fnum; j++) {
				list[j].x = list[j - 1].x + list[j - 2].x;
				list[j].y = list[j - 1].y + list[j - 2].y;
			}
			cout << list[fnum].x << " " << list[fnum].y<<endl;
		}
	}
}