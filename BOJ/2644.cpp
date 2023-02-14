#include <bits/stdc++.h>
using namespace std;
#define MX 102

int N, A, B, M;
int x, y;
vector<int> adj[MX];
int chonsu[MX];

void BFS()
{
    queue<int> q;
    chonsu[A] = 1;
    q.push(A);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        int len = adj[now].size();
        for (int i = 0; i < len; i++)
        {
            int next = adj[now][i];

            if (chonsu[next])
                continue;

            chonsu[next] = chonsu[now] + 1;
            q.push(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> A >> B >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    BFS();
    if (chonsu[B])
        cout << chonsu[B] - 1;
    else
        cout << "-1";

    return 0;
}