#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int sum = 0;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1>>n2;
		v.push_back({ n1,n2 });
	}
	sort(v.begin(), v.end());
	int start = v[0].first;
	int end = v[0].second;
	for (int i = 1; i < n; i++) {
	

		if (end > v[i].first) {
			end = max(v[i].second, end);
		}
		else {
			sum += end - start;
			start = v[i].first;
			end = v[i].second;
		}

	
	}
	sum += end - start;
	cout << sum;
}