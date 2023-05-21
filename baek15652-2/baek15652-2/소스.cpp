#include <iostream>
using namespace std;
int n, m;
int answer[10];
void solve(int num, int level) {
	if (level == m) {
		for (int i = 0; i < m; i++)
			cout << answer[i] << ' ';
		cout << '\n';
		return; 
	}
	for (int i = num; i <= n; i++)
	{
		answer[level] = i;
		solve(i , level+1);
	}
}
int main()
{
	cin >> n >> m;
	solve(1, 0);

}
