#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int N, M, a, b, c;
vector<pair<int, int>> adj[MX];
int dist[MX];

void BFS(int A, int B)
{
    for (int i = 0; i <= N; i++)
        dist[i] = 0;

    queue<int> q;
    q.push(A);
    dist[A] = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == B)
            return;
        int len = adj[now].size();

        for (int i = 0; i < len; i++)
        {
            int next = adj[now][i].first, cost = adj[now][i].second;
            if (dist[next])
                continue;

            dist[next] = dist[now] + cost;
            q.push(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        BFS(a, b);
        cout << dist[b] << "\n";
    }

    return 0;
}