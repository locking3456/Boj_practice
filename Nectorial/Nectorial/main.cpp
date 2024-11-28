#include<iostream>
#include <vector>
#include<deque>
#include <algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;


/*
 * Complete the 'Moves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */


//int Moves(vector<int> arr) {
//    int n = arr.size();
//    int halfNum = 0;
//    for (int i = 0; i < arr.size(); i++) {
//        if (arr[i] % 2 == 0) {
//            halfNum++;
//        }
//    }
//    int swapNum=0;
//    int even = 0;
//    int odd = halfNum;
//    while (even < halfNum && odd < n) {
//        while (even < halfNum && arr[even] % 2 == 0) {
//            even++;
//        }
//        while (odd < n && arr[odd] % 2 == 1) {
//            odd++;
//        }
//        if(even < halfNum && odd < n)
//            swapNum++;
//        even++;
//        odd++;
//
//    }
//    return swapNum;
//}
//
//int main() {
//    vector<int> Tc = { 82921272,
//    110219722,
//    162495938,
//    470311130,
//    583170602,
//    329963077,
//    403414481,
//    437623101,
//    485366585,
//    599466263,
//    959094281 };
//    cout<<Moves(Tc);
//}


//int nodeNum = 0;
//void dfs(int node, unordered_map<int, vector<int>> graph, vector<bool>& visited, vector<bool>& inCycle, vector<int>& stack, unordered_set<int>& visitedSet) {
//    if (visited[node]) {
//        if (find(stack.begin(), stack.end(), node) != stack.end()) {
//            for (auto it = find(stack.begin(), stack.end(), node); it != stack.end(); ++it) {
//                inCycle[*it] = true;
//            }
//        }
//        return;
//    }
//    visited[node] = true;
//    stack.push_back(node);
//    visitedSet.insert(node);
//
//    for (int neighbor : graph[node]) {
//        if (visitedSet.find(neighbor) == visitedSet.end()) {
//            dfs(neighbor, graph, visited, inCycle, stack, visitedSet);
//        }
//    }
//    stack.pop_back();
//    visitedSet.erase(node);
//}
//vector <bool> isCycle(const vector<int>& from, const vector<int>& to) {
//    unordered_map<int, vector<int>> graph;
//    int n = 6;
//    for (int i = 0; i < from.size(); i++) {
//        graph[from[i]].push_back(to[i]);
//        graph[to[i]].push_back(from[i]);
//    }
//
//    vector<bool> visited(n, false);
//    vector<bool> inCycle(n, false);
//    unordered_set<int> visitedSet;
//    for (int node = 0; node < n; node++) {
//        if (!visited[node]) {
//            vector<int>stack;
//            dfs(node, graph, visited, inCycle, stack, visitedSet);
//        }
//    }
//
//    return inCycle;
//}
////vector<int> nodeDistance(int s_nodes, vector<int> s_from, vector<int> s_to) {
////    nodeNum = s_nodes;
////
////}
//
//int main() {
//    vector<int> s_from = { 0,1,0,2,0,1 };
//    vector<int> s_to = { 1,2,2,4,3,5 };
//    vector <bool>  cycleVector = isCycle(s_from, s_to);
//    cout << "fin";
//}


long sumVips(vector<int> score, int guilder_count, int k) {
    long sumNum = 0;
    int sizeNum = score.size();
    if (sizeNum <= k) {
        for (int i = 0; i < sizeNum; i++) {
            sumNum += score[i];
        }
        return sumNum;
    }

    deque<int> frontDeque, backDeque;

    for (int i = 0; i < k; i++) {
        while (!frontDeque.empty() && score[i] >= score[frontDeque.back()]) {
            frontDeque.pop_back();
        }
        frontDeque.push_back(i);
    }

    for (int i = sizeNum-1; i >= sizeNum - k; i--) {
        while (!backDeque.empty() && score[i] >= score[backDeque.back()]) {
            backDeque.pop_back();
        }
        backDeque.push_back(i);
    }

    for (int i = 0; i < guilder_count; i++) {
        int frontMax = score[frontDeque.front()];
        int backMax = score[backDeque.front()];

        if (frontMax >= backMax) {
            sumNum += frontMax;
            score.erase(score.begin() + frontDeque.front());
        }
        else {
            sumNum += backMax;
            score.erase(score.begin()+ backDeque.front());
        }

        if (!frontDeque.empty() && frontDeque.front() <= i - k) {
            frontDeque.pop_front();
        }
        if (!backDeque.empty() && backDeque.front() >= sizeNum - k + i) {
            backDeque.pop_front();
        }
    }

    return sumNum;
}

int main() {
    vector<int> Tc = { 8,6,18,8,14,10,12,18,9,8};
    int cnt = 3;
    int k = 4;
    cout<<sumVips(Tc, cnt, k);
}

//int dp[100001] = { 1, };
//int minDeletions(vector<int> arr) {
//    
//    int n;
//    int lis = 0;
//    n = arr.size();
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            if (arr[i] > arr[j]) {
//                dp[i] = max(dp[i], dp[j] + 1);
//                lis = max(lis, dp[i]);
//            }
//        }
//    }
//    return lis;
//}
//int main() {
//    vector<int>TC = { 1,5,10 };
//    cout<<minDeletions(TC);
//}
