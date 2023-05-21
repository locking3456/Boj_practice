#include <iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int n;
int ans = 10000;
bool isused[21];
int squad[21][21];
void solve(int level, int pos) {
	if (level == n / 2) {
		int team1=0;
		int team2=0;
		for (int k = 0; k <= n; k++) {
			for (int j = 0; j <= n; j++) {
				if (isused[k] == true && isused[j] == true)
					team1 += squad[k][j];
				if (isused[k] == false && isused[j] == false)
					team2 += squad[k][j];
			}
		}
		int temp = abs(team2 - team1);
		if (ans > temp)
			ans = temp;
		return;
	}
	for (int i = pos; i < n; i++) {

		isused[i] = true;
		solve(level + 1,i+1);
		isused[i] = false;
	}

}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &squad[i][j]);
		}
	}
	solve(0,1);
	printf("%d", ans);
}