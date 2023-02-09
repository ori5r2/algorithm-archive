#include <bits/stdc++.h>
using namespace std;
#define MX 50005
#define INF 1987654321

struct edge
{
    int end;
    int cost;
    bool operator<(const edge &b) const { return cost > b.cost; }
};
vector<edge> adj[MX];
int N, M;
int A, B, C;
int dist[MX];

void dijk(void)
{
    // 초기화
    for (int i = 0; i <= N; i++)
        dist[i] = INF;

    priority_queue<edge> pq;
    pq.push({1, 0}), dist[1] = 0;

    while (!pq.empty())
    {
        edge top = pq.top();
        pq.pop();
        int nowVertex = top.end, nowCost = top.cost;
        int len = adj[nowVertex].size();

        if (nowCost > dist[nowVertex])
            continue;

        for (int i = 0; i < len; i++)
        {
            edge next = adj[nowVertex][i];
            int nextVertex = next.end, nextCost = next.cost;
            if (dist[nextVertex] > dist[nowVertex] + nextCost)
            {
                dist[nextVertex] = dist[nowVertex] + nextCost;
                pq.push({nextVertex, dist[nextVertex]});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }

    dijk();
    cout << dist[N];
    return 0;
}