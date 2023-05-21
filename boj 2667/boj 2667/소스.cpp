#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int map[26][26];
bool visited[26][26];
int countnum = 0;
int danjicount = 0;
vector<int> answer;
void dfs(int i, int j) {
	countnum++;
	visited[i][j] = true;
	if ((!visited[i][j + 1]) && map[i][j+1]==1)
		dfs(i, j + 1);
	if ((!visited[i][j - 1]) && map[i][j - 1]==1)
		dfs(i, j - 1);
	if ((!visited[i - 1][j]) && map[i-1][j]==1)
		dfs(i - 1, j);
	if ((!visited[i + 1][j]) && map[i + 1][j]==1)
		dfs(i + 1, j);
}
int main() {
	int N;
	string temp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		for (int j = 0; j <N; j++) {
			map[i][j + 1] = temp[j]-'0';
		}
	} 

	for (int i = 1; i <= N; i++) {	
		for (int j = 1; j <= N; j++) {
			countnum = 0;
			if (visited[i][j] || map[i][j]==0)
				continue;
			dfs(i, j);
			danjicount++;
			if(countnum)
				answer.push_back(countnum);
		}
	}
	
	sort(answer.begin(), answer.end());
	cout << danjicount << '\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}

}