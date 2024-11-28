#include <iostream>
using namespace std;
long  long arr[1000001];
long  long n;
long  long numCnt;
long  long idxOfNum = 10;
void makeDecreaseNum(long  long num , long  long numOfone , long  long cntOfNum) {
	if (cntOfNum==numCnt) {
		arr[idxOfNum] = num;
		idxOfNum++;
	}
	else {
		num = num * 10;
		for (long  long i = 0; i < numOfone; i++) {
			makeDecreaseNum(num + i, i, cntOfNum+1);
		
		}
	}

}
int main() {
	cin >> n;
	for (long  long i = 0; i < 1000001; i++) {
		arr[i] = -1;
	}
	for (long  long i = 0; i < 10; i++) {
		arr[i] = i;
	}
	for (long  long i = 2; i <= 11; i++) {
		numCnt = i;
		for (long  long j = 1; j <= 9; j++) {
			makeDecreaseNum(j, j, 1);
		}
	}
	cout << arr[n];
}