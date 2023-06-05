#include<iostream>
#include<algorithm>
#include<queue>
#include <vector>
using namespace std;
int N;
vector<pair<int, int>> classt;
priority_queue< int, vector<int>, greater<int> > pqmin;
int greedy(int classc) {
	pqmin.push(classt[0].second);
	for (int i = 1; i < classc; i++) {
		pqmin.push(classt[i].second);
		if (pqmin.top() <= classt[i].first) {
			pqmin.pop();
		}
	}
	return pqmin.size();
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		classt.push_back(make_pair(start, end));
	}
	sort(classt.begin(), classt.end());
	cout << greedy(N)<<endl;
}