#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int arr[100] = { 0, };
vector<int> frame;

int main() {
	cin >> N >> M;
	int num;
	vector<int>::iterator iter = frame.begin();
	for (int i = 0; i < M; i++) {
		cin >> num;
		if ((frame.size() < N) && (arr[num]==0)) {
			frame.push_back(num);
			arr[num]++;
		}
		else if ((frame.size() < N) & (arr[num] != 0)) {
			arr[num]++;
		}
		else {
			int minnum = M + 1;
			int minindex = 0;
			for (int i = 0; i < frame.size(); i++) {
				if (arr[frame[i]] < minnum) {
					minnum = arr[frame[i]];
					minindex = i;
				}
			}
			if (arr[num] != 0) {
				arr[num]++;
			}
			else {
				arr[frame[minindex]] = 0;
				frame.push_back(num);
				iter = frame.begin();
				iter = iter + minindex;
				iter = frame.erase(iter);
				arr[num]++;
			}
		}
	}
	sort(frame.begin(), frame.end());
	for (int i = 0; i < frame.size(); i++) {
		cout << frame[i]<<" ";
	}
}

