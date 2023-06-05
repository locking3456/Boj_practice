//#include <stdio.h>
//
//int N;
//int arr[6 + 2][2 + 2]; 
//int cnt[4];
//
//int main(void) {
//
//    int s = 1; 
//    int b = 1; 
//
//    scanf("%d", &N);
//    for (int i = 0; i < 6; i++) {
//        scanf("%d %d", &arr[i][0], &arr[i][1]);
//        cnt[arr[i][0]]++;
//    }
//
//    for (int i = 0; i < 6; i++) {
//
//        if (cnt[arr[i][0]] == 1) {
//            b *= arr[i][1]; 
//            continue;
//        }
//
//        int n = (i + 1) % 6;
//        int nn = (i + 2) % 6;
//        if (arr[i][0] == arr[nn][0]) s *= arr[n][1];
//    }
//
//    printf("%d", (b - s) * N);
//
//    return 0;
//}
#include <iostream>
using namespace std;
int N;
int bCnt;
int wCnt;
int arr[128][128];
int bSolution(int x, int y , int size) {
	if (size == 0) {
		return 0;
	}
	int check=0;
	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y+size; j++) {
			if (arr[i][j] != 1) {
				check = 1;
				break;
			}
		}
		if (check == 1)
			break;
	}
	if (check == 1) {
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (arr[i][j] != 0) {
					check = 2;
					break;
				}
			}
			if (check == 2)
				break;
		}

	}
	if (check == 0) {
		bCnt++;
	}
	else if (check == 1) {
		wCnt++;
	}
	else {
		bSolution(x, y, size / 2);
		bSolution(x, y + size / 2, size / 2);
		bSolution(x + size / 2, y, size / 2);
		bSolution(x + size / 2, y + size / 2, size / 2);
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	bSolution(0, 0, N);
	cout << wCnt<<endl;
	cout << bCnt << endl;
}