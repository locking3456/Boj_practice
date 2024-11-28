#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int parent[200];

int GetParent(int x) {
    if (parent[x] == x)
        return parent[x];
    else {
        parent[x] = GetParent(parent[x]);
        return parent[x];
    }
}

bool IsSameParent(int x, int y) {
    if (GetParent(x) != GetParent(y)) {
        return false;
    }
    else
        return true;
}

void MakeSameParent(int x, int y) {
    if (!IsSameParent(x, y)) {
        parent[GetParent(y)] = GetParent(x);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    set<int> s;
    for (int i = 0; i < n ; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(computers[i][j]==1)
                MakeSameParent(i, j);
        }
    }

    for (int i = 0; i < n ; i++) {
        s.insert(GetParent(parent[i]));
    }

    answer = s.size();
    return answer;
}

int main() {
    vector<vector<int>> computers = { {1,1,1},{1,1,0},{1,0,1} };
    int n = 3;

    cout<<solution(3, computers);
}