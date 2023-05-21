#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> solution(string msg) {
    vector<int> answer;
    char start = 'A';
    int k = 0;
    vector<string> dictionary;
    for (int i = 1; i <= 26; i++) {
        dictionary.push_back(string(1, start));
        start++;
    }


    for (int i = 0; i < msg.length(); i++) {
        string temp = string(1,msg[i]);
        int endnumber=0;
        for (int j = 0; j < dictionary.size(); j++) {
            if (temp == dictionary[j]) {
                temp = temp + msg[i += 1];
                endnumber = j+1;
            }
        }
        answer.push_back(endnumber);
        if ((i) == msg.length()) {
            continue;
        }
        dictionary.push_back(temp);
        if (i >= 1) {
            i = i - 1;
        }
    }
    return answer;
}
int main() {
    vector<int> answe1r;
    answe1r=solution("TOBEORNOTTOBEORTOBEORNOT");
    for (int i = 0; i < answe1r.size(); i++) {
        cout << answe1r[i] << '\n';
    }
    
}

//#include <string>
//#include <vector>
//#include <math.h>
//#include <set>
//
//using namespace std;
//
//bool visited[8];
//set<int> s;
//
//bool isPrime(int n)
//{
//    if (n == 1 || n == 0)
//        return false;
//
//    for (int i = 2; i <= sqrt(n); i++)
//        if (n % i == 0)
//            return false;
//
//    return true;
//}
//
//void Dfs(int now, string str, string numbers)
//{
//    if (now == numbers.size())
//    {
//        if (str.empty())
//            return;
//
//        int target = stoi(str);
//        if (isPrime(target))
//            if (s.find(target) == s.end()) s.insert(target);
//
//        return;
//    }
//
//    for (int i = 0; i < numbers.size(); i++)
//    {
//        if (visited[i])
//            continue;
//
//        visited[i] = true;
//        Dfs(now + 1, str, numbers);
//        Dfs(now + 1, str + numbers[i], numbers);
//        visited[i] = false;
//    }
//}
//
//int solution(string numbers)
//{
//    Dfs(0, "", numbers);
//
//    return s.size();
//}