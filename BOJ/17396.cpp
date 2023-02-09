#include <bits/stdc++.h>
using namespace std;
#define MX 100002
#define INF 9223372036854775807

struct edge
{
    int end;
    long long time;

    bool operator<(const edge &b) const
    {
        return time > b.time;
    }
};
priority_queue<edge> pq;
vector<edge> adj[MX];
long long dist[MX];
bool isPossible[MX];
int N, M, a, b, t, tmp;

void dijk()
{
    // 초기화
    for (int i = 0; i < N; i++)
        dist[i] = INF;
    pq.push({0, 0}), dist[0] = 0;

    while (!pq.empty())
    {
        int nowVertex = pq.top().end;
        long long nowTime = pq.top().time;
        int len = adj[nowVertex].size();
        pq.pop();

        if (nowTime > dist[nowVertex])
            continue;

        for (int i = 0; i < len; i++)
        {
            edge next = adj[nowVertex][i];
            int nextVertex = next.end;
            long long nextTime = next.time;

            if (dist[nextVertex] > dist[nowVertex] + nextTime)
            {
                dist[nextVertex] = dist[nowVertex] + nextTime;
                pq.push({nextVertex, dist[nextVertex]});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;

        if (i == 0 || i == N - 1)
            isPossible[i] = true;
        else
        {
            if (tmp == 0)
                isPossible[i] = true;
            else
                isPossible[i] = false;
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> t;
        if (isPossible[a] == false || isPossible[b] == false)
            continue;
        else
        {
            adj[a].push_back({b, t});
            adj[b].push_back({a, t});
        }
    }

    dijk();
    if (dist[N - 1] == INF)
        cout << "-1";
    else
        cout << dist[N - 1];

    return 0;
}