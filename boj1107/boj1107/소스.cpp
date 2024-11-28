#include<iostream>
#include<stdlib.h>
int N,M;
bool arr[10];
int psearch = 1000000;  
int nsearch = 1000000;
int hsearch;
using namespace std;
int solution(int n) {
	if (n < 10) {
		if (!arr[n]) {
			return 1;
		}
	}
	else if (n < 100) {
		if (!arr[n / 10] && !arr[n % 10]) {
			return 2;
		}
	}
	else if (n < 1000) {
		if (!arr[n/100] && !arr[n%100 / 10] && !arr[n % 10]) {
			return 3;
		}
	}
	else if (n < 10000) {
		if (!arr[n/1000] && !arr[n%1000 / 100] && !arr[n%100 / 10] && !arr[n % 10]) {
			return 4;
		}
	}
	else if (n < 100000) {
		if (!arr[n / 10000] && !arr[n%10000 / 1000] && !arr[n%1000 / 100] && !arr[n%100 / 10] && !arr[n % 10]) {
			return 5;
		}
	}
	else if(n<1000000){
		if (!arr[n / 100000] && !arr[n%100000 / 10000] && !arr[n%10000 / 1000] && !arr[n%1000 / 100] && !arr[n%100 / 10] && !arr[n % 10]) {
			return 6;
		}
	}
	return false;
}
int main() {
	cin >> N >> M;
	int searchNum1,searchNum2;
	int answer = 0;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		arr[temp] = true;
	}
	searchNum1 = N;
	searchNum2 = N;


	while (true) {
		if (solution(searchNum1) && (searchNum1 >= 0)) {
			psearch = solution(searchNum1) + (N - searchNum1);
			break;
		}
		searchNum1--;
		if (searchNum1 < 0)
			break;
	}

	while (true) {
		if (solution(searchNum2) && (searchNum1 <=1000000)) {
			nsearch = solution(searchNum2) + (searchNum2-N);
			break;
		}
		searchNum2++;
		if (searchNum2 > 1000000)
			break;
	}
	hsearch = abs(N - 100);
	if (psearch > nsearch) {
		answer = nsearch;
	}
	else {
		answer = psearch;
	}

	if (answer > hsearch) {
		answer = hsearch;
	}

	cout << answer;
}
