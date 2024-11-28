#include<iostream>
using namespace std;
int isVisited[20][20];
bool isUsed[26];
char arr[20][20];
int maxNum = 0;
int GetIdxOfAlphabet(char ch);
bool isCanGo(int idxX, int idxY) {
	if (idxX < 0 || idxY < 0 || idxX>19 || idxY > 19 || (isVisited[idxX][idxY] == true) || (isUsed[GetIdxOfAlphabet(arr[idxX][idxY])]==true)) {
		return false;
	}

	return true;
}
void dfs(int startX, int startY, int cnt) {
	if (!isCanGo(startX, startY)) {
		if (cnt-1 > maxNum) {
			maxNum=cnt-1;
			return;
		}
	}
	else {
		isUsed[GetIdxOfAlphabet(arr[startX][startY])] = true;
		isVisited[startX][startY] = true;
		dfs(startX + 1, startY, cnt + 1);
		dfs(startX -1, startY, cnt + 1);
		dfs(startX, startY+1, cnt + 1);
		dfs(startX, startY-1, cnt + 1);
		isUsed[GetIdxOfAlphabet(arr[startX][startY])] = false;
		isVisited[startX][startY] = false;
	}
}

int GetIdxOfAlphabet(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		int position = ch - 'A';
		return position;
	}
	else
		return 0;
}
int main() {
	int r, c;
	cin >> r >> c;
	char inputString[21];
	for (int i = 0; i < r; i++) {
		cin >> inputString;
		for (int j = 0; j < c; j++) {
			arr[i][j] = inputString[j];
		}
	}
	dfs(0, 0, 1);
	cout << maxNum;
	return 0;
} 