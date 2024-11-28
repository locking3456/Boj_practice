#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	int l;
	int test;
	pair<int, int> startPoint;
	pair<int, int>endPoint;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> test;
		int arr[300][300] = { 0, };
		int tempx=0, tempy=0;
		cin >> startPoint.first >> startPoint.second;
		cin >> endPoint.first >> endPoint.second;
		queue<pair<int, int>> bfsQueue;
		bfsQueue.push(make_pair(startPoint.first, startPoint.second));
		while (!bfsQueue.empty()) {
			tempx = bfsQueue.front().first;
			tempy = bfsQueue.front().second;
			bfsQueue.pop();
			if (tempx == endPoint.first && tempy == endPoint.second) {
				cout << arr[tempx][tempy]<<endl;
				break;
			}
			else {
				if (arr[tempx - 2][tempy - 1] == 0) {
					if(tempx-2>=0&&tempy-1>=0){
						bfsQueue.push(make_pair(tempx - 2, tempy - 1));
						arr[tempx - 2][tempy - 1] = arr[tempx][tempy] + 1;
					}
				}
				if (arr[tempx - 1][tempy - 2] == 0) {
					if (tempx - 1 >= 0 && tempy - 2 >= 0) {
						bfsQueue.push(make_pair(tempx - 1, tempy - 2));
						arr[tempx - 1][tempy - 2] = arr[tempx][tempy] + 1;
					}
				}
				if (arr[tempx + 2][tempy - 1] == 0) {
					if (tempx + 2 < test && tempy - 1 >= 0)
					{
						bfsQueue.push(make_pair(tempx + 2, tempy - 1));
						arr[tempx + 2][tempy - 1] = arr[tempx][tempy] + 1;
					}
				}
				if (arr[tempx +1][tempy - 2] == 0) {
					if (tempx + 1 < test && tempy - 2 >= 0) 
					{
						bfsQueue.push(make_pair(tempx + 1, tempy - 2));
						arr[tempx + 1][tempy - 2] = arr[tempx][tempy] + 1;
					}
				}
				if (arr[tempx -2][tempy + 1] == 0) {
					if (tempx - 2 >= 0 && tempy + 1 < test) {
						bfsQueue.push(make_pair(tempx - 2, tempy + 1));
						arr[tempx - 2][tempy + 1] = arr[tempx][tempy] + 1;
					}
				}
				if (arr[tempx - 1][tempy +2] == 0) {
					if (tempx - 1 >= 0 && tempy + 2 < test) {
						bfsQueue.push(make_pair(tempx - 1, tempy + 2));
						arr[tempx - 1][tempy + 2] = arr[tempx][tempy] + 1;
					}
				}
				if (arr[tempx + 2][tempy + 1] == 0) {
					if (tempx + 2 < test && tempy + 1 < test) {
						bfsQueue.push(make_pair(tempx + 2, tempy + 1));
						arr[tempx + 2][tempy + 1] = arr[tempx][tempy] + 1;
					}
				}
				if (arr[tempx + 1][tempy + 2] == 0) {
					if (tempx + 1 < test && tempy + 2 < test) {
						bfsQueue.push(make_pair(tempx + 1, tempy + 2));
						arr[tempx + 1][tempy + 2] = arr[tempx][tempy] + 1;
					}
				}
			}
		}
	}
}