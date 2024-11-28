#include<iostream>
#include<queue>
using namespace std;
int day[1001] = {};
struct Compare {
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
        return p1.second < p2.second;
    }
};
priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
int main() {
    int N;
    cin >> N;
    int num1, num2;
    int maxIdx=0;
    int result = 0;
    for (int i = 0; i < N; i++) {
        cin >> num1 >> num2;
        if (num1 > maxIdx) {
            maxIdx = num1;
        }
        pq.push({ num1,num2 });
    }

    while (!pq.empty()) {
        int x, y;
        x = pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (day[x]== 0) {
            day[x] = y;
        }
        else {
            for (int i = x - 1; i > 0; i--) {
                if (day[i] == 0) {
                    day[i] = y;
                    break;
                }
            }
        }

    }
    for (int i = maxIdx; i > 0; i--) {
        result += day[i];
    }
    cout << result;
}