#include <iostream>
#include <vector>
using namespace std;
vector<int> primeNumbers;
vector<int> check;

//n 이하의 정수에 대한 소수를 에라토스테네스의 체로  걸러냄
void getPrimeNumbers(int n) {
	for (int i = 2; i <= n; i++) {
		if (check[i])
			continue;
		else {
			primeNumbers.push_back(i);
			for (int j = i; j <= n; j += i) {
				check[j] = 1;
			}
		}
	}
}
int main() {
	int n,start,end,cnt;
	cin >> n;
	check.resize(n + 1, 0);
	getPrimeNumbers(n);
	start = primeNumbers[0];
	end = primeNumbers[0];
	int startidx = 0;
	int endidx = 0;
	cnt = 0;
	while (startidx <= endidx && endidx<primeNumbers.size()) {
		int sum = 0;
		for (int i = startidx; i <= endidx; i++) {
			sum += primeNumbers[i];
		}
		if (sum == n) {
			cnt += 1;
			startidx += 1;
			endidx += 1;
		}
		else  if (sum < n) {
			endidx += 1;
		}
		else {
			startidx += 1;
		}	
	}
	cout << cnt;
}