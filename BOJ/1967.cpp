#include <bits/stdc++.h>
using namespace std;
#define MX 10002

int N, a, b, c, maxVal;
int dist[MX];
vector<pair<int, int>> adj[MX];
queue<int> q;

void BFS(int startNode)
{
    for (int i = 0; i <= N; i++)
        dist[i] = 0;
    q.push(startNode);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        int len = adj[now].size();

        for (int d = 0; d < len; d++)
        {
            int next = adj[now][d].first, cost = adj[now][d].second;
            if (dist[next])
                continue;
            if (next == startNode) // startNode의 dist 0이기 때문에 visited를 따로 만들어주던가 확인할 필요 있음
                continue;

            dist[next] = dist[now] + cost;
            maxVal = max(dist[next], maxVal);
            q.push(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 1; i <= N; i++)
        BFS(i);

    cout << maxVal;
    return 0;
}