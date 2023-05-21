#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n,begin,end;
	vector<pair<int, int>>table;
	int count1 = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> begin >> end;
		table.push_back(make_pair(end, begin));
	}
	sort(table.begin(), table.end());
	int time = table[0].first;
	for (int i = 1; i < n; i++) {
		if (time <= table[i].second) {
			count1 += 1;
			time = table[i].first;
		}
	}
	cout << count1;

}

