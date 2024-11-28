#include<iostream>
#include<stack>
#include<vector>
#include <algorithm>
using namespace std;
stack<long long> bigStack;
stack<long long> answerStack;
long long n, k;
string num;
vector<long long> arr;
long long popCount=0;
long long result = 0;
int main() {
	cin >> n >> k;
	cin >> num;
	for (int i = 0; i < num.length(); ++i) {
		arr.push_back(num[i] - '0');  // 문자 '0'을 빼서 실제 숫자로 변환
	}

	if(arr.size()!=0)
		bigStack.push(arr[0]);
	for (long long i = 1; i < n; i++) {
		while (!bigStack.empty()&& bigStack.top() < arr[i] && popCount<k) {
			bigStack.pop();
			popCount += 1;
		}
		bigStack.push(arr[i]);
	}
	while (popCount < k) {
		bigStack.pop();
		popCount += 1;
	}
	while (!bigStack.empty()) {
		answerStack.push(bigStack.top());
		bigStack.pop();
	}

	while (!answerStack.empty()) {
		cout << answerStack.top();
		answerStack.pop();
	}

}