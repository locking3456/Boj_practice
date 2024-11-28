#include <queue>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int a, b;
bool visited[10000];
int logicD(int num) {
    return (num * 2) % 10000;
}

int logicS(int num) {
    return num - 1 < 0 ? 9999 : num - 1;
}

int logicL(int num) {
    return (num % 1000) * 10 + (num / 1000);
}

int logicR(int num) {
    return num / 10 + (num % 10) * 1000;
}
void bfs()
{
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    visited[a] = true;

    while (!q.empty())
    {
        int cur_num = q.front().first;
        string cur_op = q.front().second;
        q.pop();

        if (cur_num == b)
        {
            cout << cur_op << '\n';
            return;
        }

        int D, S, L, R;
        D = logicD(cur_num);
        if (!visited[D])
        {
            visited[D] = true;
            q.push(make_pair(D, cur_op + "D"));
        }
        S = logicS(cur_num);
        if (!visited[S])
        {
            visited[S] = true;
            q.push(make_pair(S, cur_op + "S"));
        }
        L = logicL(cur_num);
        if (!visited[L])
        {
            visited[L] = true;
            q.push(make_pair(L, cur_op + "L"));
        }
        R = logicR(cur_num);
        if (!visited[R])
        {
            visited[R] = true;
            q.push(make_pair(R, cur_op + "R"));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T;
    cin >> T;

    while (T--)
    {
        cin >> a >> b;
        memset(visited, false, sizeof(visited)); // √ ±‚»≠
        bfs();
    }

    return 0;
}

