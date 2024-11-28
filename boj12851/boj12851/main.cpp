#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>>bfsQ;
bool isVisited[100001];
bool canGo(int x) {
	if (x >= 0 && x <= 100000) {
		return true;
	}
	else
		return false;
}
int minNum=100001;
int countOfMin = 0;
int p1, p2;
int main() {
	cin >> p1 >> p2;
	bfsQ.push({ p1,0 });
	while (!bfsQ.empty()) {
		int nowPos = bfsQ.front().first;
		int cnt = bfsQ.front().second;
		bfsQ.pop();
		if (nowPos == p2 && cnt<minNum) {
			cnt = minNum;
			countOfMin = 1;	
		}
		else if (nowPos == p2 && cnt == minNum) {
			countOfMin += 1;
		}
		else if (nowPos == p2 && cnt > minNum) {
			break;
		}
		if (canGo(nowPos + 1)) {
			bfsQ.push({ nowPos + 1,cnt + 1 });
		}
		if (canGo(nowPos - 1)) {
			bfsQ.push({ nowPos - 1,cnt + 1 });
		}
		if (canGo(nowPos * 2)) {
			bfsQ.push({ nowPos * 2,cnt + 1 });
		}
	}
	cout << countOfMin;
}