#include <iostream>
#include <cstdio>
using namespace std;
int count1 = 0;;
int matarr[9][9];
bool colused[9][10];
bool rowused[9][10];
bool blockused[9][10];
bool willexit = false;
bool check1(int i,int j,int k) {
	if (colused[i][k] == false && rowused[j][k] == false && blockused[(i / 3) * 3 + j / 3][k] == false) {
		colused[i][k] = true;
		rowused[j][k] =true;
		blockused[(i / 3) * 3 + j / 3][k] = true;
		return true;
	}
	else
		return false;

}
void solve(int level) {
	if (level == count1) {
		willexit = true;
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matarr[i][j] != 0)
				continue;
			for (int k = 1; k < 10; k++) {
				matarr[i][j] = k;
				if (check1(i, j, k)) {

					solve(level + 1);
					colused[i][k] = false;
					rowused[j][k] = false;
					blockused[(i / 3) * 3 + j / 3][k] = false;
				}
				if (willexit) {
					break;
				}
			}
			if (willexit) {
				break;
			}
			matarr[i][j] = 0;
			return;
		}
		if (willexit) {
			break;
		}
	}
}
int main() {
	int k;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &k);
			matarr[i][j] = k;
			colused[i][k] = true;
			rowused[j][k] = true;
			blockused[(i / 3) * 3 + j / 3][k] = true;
			if (matarr[i][j] == 0)
				count1 = count1 + 1;
		}
	}

	solve(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", matarr[i][j]);
		}
		printf("\n");
	}
}