#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	unsigned long long n, m;
	vector <unsigned long long > times;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		unsigned long long tmp1;
		cin >> tmp1;
		times.push_back(tmp1);
	}

	sort(times.begin(), times.end());
	unsigned long long answer = 0;
	unsigned long min = 1;
	unsigned long long max = m * times.back();

	while (min <= max) {
		unsigned long long tmp = 0;
		unsigned long long avg = (min + max) / 2;
		for (unsigned long long i = 0; i < n; i++) {
			tmp += avg / times[i];
		}

		if (tmp < m) {
			min = avg + 1;
		}
		else {
			max = avg - 1;
			answer = avg;
		}
	}
	cout << answer;
}