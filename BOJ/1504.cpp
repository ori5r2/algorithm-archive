#include <bits/stdc++.h>
using namespace std;
#define MX 802
#define INF 200000002

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

int N, E, V1, V2;
int a, b, c;
int dist[MX];

void dijk(int startNode)
{
    priority_queue<edge> pq;

    for (int i = 0; i <= N; i++)
        dist[i] = INF;
    pq.push({startNode, 0}), dist[startNode] = 0;

    while (!pq.empty())
    {
        int nowV = pq.top().end, nowCost = pq.top().cost;
        pq.pop();

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
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> V1 >> V2;

    int ret1 = 0, ret2 = 0;
    dijk(1);
    // 1 -> V1 -> V2 -> N // ⭐️ V1 -> V2로 가는데 다익스트라로 해야함
    // 1 -> V2 -> V1 -> N

    ret1 += dist[V1];
    ret2 += dist[V2];

    dijk(V2), ret1 += dist[V1], ret1 += dist[N], ret2 += dist[V1];
    dijk(V1), ret2 += dist[N];

    int minVal = min(ret1, ret2);

    if (minVal >= INF)
        cout << "-1";
    else
        cout << minVal;

    return 0;
}