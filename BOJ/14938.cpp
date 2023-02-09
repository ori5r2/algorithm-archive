#include <bits/stdc++.h>
using namespace std;
#define MX 102
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
int n, m, r;
int a, b, l;
int items[MX], dist[MX];

int dijk(int startNode)
{
    // 초기화
    priority_queue<edge> pq;
    for (int i = 0; i <= n; i++)
        dist[i] = INF;
    pq.push({startNode, 0}), dist[startNode] = 0;

    while (!pq.empty())
    {
        edge top = pq.top();
        pq.pop();
        int nowVertex = top.end, nowCost = top.cost;
        int len = adj[nowVertex].size();

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

    int itemCnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] <= m)
            itemCnt += items[i];
    }

    return itemCnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        cin >> items[i];

    for (int i = 0; i < r; i++)
    {
        cin >> a >> b >> l;
        adj[a].push_back({b, l});
        adj[b].push_back({a, l});
    }

    int maxItem = 0;
    for (int i = 1; i <= n; i++)
    {
        int total = dijk(i);
        maxItem = max(total, maxItem);
    }

    cout << maxItem;
    return 0;
}