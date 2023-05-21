#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> score[100000];
int answer[20];
int main() {
	int testnum;
	cin >> testnum;
	for (int i = 0; i < testnum; i++) {
		int countnum = 0;
		int candidatenum;
		cin >> candidatenum;
		for (int j = 0; j < candidatenum; j++) {
			cin >> score[j].first >> score[j].second;
		}
		sort(score, score + candidatenum);
		int maxscore = score[0].second;

		for (int j = 0; j < candidatenum; j++) {
			if (score[j].second <= maxscore) {
				countnum++;
				maxscore = score[j].second;
			}

		}
		answer[i] = countnum;
	}
	for (int i = 0; i < testnum; i++) {
		cout << answer[i] << '\n';
	}
}