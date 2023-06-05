#include <iostream>
#include<queue>
using namespace std;
int T;
queue <int> n;
int answer[12];
int solution(int start,int answerindex) {
	if (start == answerindex) {
		answer[answerindex]++;
	}
	else if (start > answerindex) {
		return 0;
	}
	else {
		solution(start + 1, answerindex);
		solution(start + 2, answerindex);
		solution(start + 3, answerindex);
	}
	return 0;
}
int main() {
	cin >> T;
	int temp;
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= T; i++) {
		cin >> temp;
		n.push(temp);
	}
	while (!n.empty()) {
		temp = n.front();
		n.pop();
		solution(0, temp);
		cout << answer[temp] << endl;
	}
}