#include <iostream>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
int arr[20][20];
vector<int> team1;
vector<int> team2;
int maxresult = 1e9;
int teamP[2097152];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			int teamNum = (1 << i) | (1 << j);
			teamP[teamNum] = arr[i][j]+arr[j][i];
		}
	}
	int sum1 = 0;
	int sum2 = 0;
	
	for (int i = 1; i < (1<<n); i++) {
		for (int j = 0; j <= n; j++) {
			if (i & (1 << j))
				team1.push_back(j);
			else
				team2.push_back(j);
		}
		for (int k = 0; k < team1.size(); k++) {
			for (int p = k + 1; p < team1.size(); p++) {
				sum1 += teamP[(1 << team1[k]) | (1 << team1[p])];
			}
		}
		for (int k = 0; k < team2.size(); k++) {
			for (int p = k + 1; p < team2.size(); p++) {
				sum2 += teamP[(1 << team2[k]) | (1 << team2[p])];
			}
		}
		if (team1.size() && team2.size())
			maxresult = min(maxresult, abs(sum1 - sum2));
		team1.clear();
		team2.clear();
		sum1 = 0;
		sum2=0;
	}

	cout << maxresult;
}