#include <bits/stdc++.h>
using namespace std;
#define MX 5005
#define INF 1987654321

struct edge
{
    int end;
    int cost;
    bool operator<(const edge &b) const
    {
        return cost > b.cost;
    }
};

vector<edge> adj[MX];
int N, M, S, T;
int a, b, c;
int dist[MX];
priority_queue<edge> pq;

void dijk(int startNode)
{
    for (int i = 0; i <= N; i++)
        dist[i] = INF;
    pq.push({startNode, 0}), dist[startNode] = 0;

    while (!pq.empty())
    {
        int nowV = pq.top().end, nowCost = pq.top().cost;
        pq.pop();
        if (dist[nowV] < nowCost)
            continue;

        int len = adj[nowV].size();
        for (int i = 0; i < len; i++)
        {
            int nextV = adj[nowV][i].end, nextCost = adj[nowV][i].cost;
            if (dist[nextV] > dist[nowV] + nextCost)
            {
                dist[nextV] = dist[nowV] + nextCost;
                pq.push({nextV, dist[nextV]});
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
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> S >> T;
    dijk(S);
    cout << dist[T];

    return 0;
}