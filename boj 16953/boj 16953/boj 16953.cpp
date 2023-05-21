#include <iostream>
using namespace std;
int main() {
	int A, B;
	int countnum=0;
	cin >> A >> B;
	while (true) {
		if (A == B) {
			countnum += 1;
			break;
		}
		if (A > B) {
			countnum= -1;
			break;
		}
		if (B % 10 == 1) {
			B--;
			B = B / 10;
			countnum++;
		}
		else if (B % 2 == 0) {
			B = B / 2;
			countnum++;
		}
		else {
			countnum= -1;
			break;
		}
	}
	cout << countnum;

}