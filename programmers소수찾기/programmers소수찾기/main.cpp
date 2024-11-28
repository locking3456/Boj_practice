#include <string>
#include <vector>
#include <cmath>
#include<iostream>
using namespace std;
int num = 999999999;
int cnt = 0;
string numberString;
vector<bool> isPrime(num + 1, true);
vector<bool> alreadyMade(num + 1, false);
bool isUsed[7];
void makePrimeNumber() {
    num = (int)pow(10, numberString.size()) + 1;
    for (int i = 2; i * i <= num + 1; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= num; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}
void makeNum(int num) {
    num *= 10;
    for (int i = 0; i < numberString.size(); i++) {
   
        if (!isUsed[i]) {
            int madeNumber = num + (numberString[i] - '0');
            if (isPrime[madeNumber] && !alreadyMade[madeNumber]) {
                cnt += 1;
                alreadyMade[madeNumber] = true;
            }
            isUsed[i] = true;
            makeNum(madeNumber);
            isUsed[i] = false;
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    numberString = numbers;
    makePrimeNumber();
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i] -'0';
        isUsed[i] = true;
        if (isPrime[num] && !alreadyMade[num]) {
            cnt += 1;
        }
        alreadyMade[num] = true;
        makeNum(num);
        isUsed[i] = false;
    }
    answer = cnt;
    return answer;
}
int main() {
    solution("17");
    cout << cnt;
}