#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
int alpha[26];
using namespace std;
string wordList[10];
bool compare(int i, int j) {
	return j < i;
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	int num = 9;
	int sum=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> wordList[i];
	}
	for (int i = 0; i < N; i++) {
		int k = 0;
		for (int j = wordList[i].size()-1; j >=0; j--) {
			alpha[wordList[i][j] - 'A'] += pow(10,k);
			k++;
		}
	}
	sort(alpha, alpha + 26,compare);
	for (int i = 0; i < 10; i++) {
		sum += alpha[i] * num;
		num--;
	}
	cout << sum;
}