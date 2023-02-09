#include <bits/stdc++.h>
using namespace std;
#define MX 10002
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
int t, n, d, c, a, b, s; // input
int dist[MX];

void init()
{
    for (int i = 0; i <= n; i++)
        dist[i] = INF;
}

void dijk(int startNode, vector<edge> adj[MX])
{
    // 초기화
    init();
    priority_queue<edge> pq;
    pq.push({startNode, 0}), dist[startNode] = 0;

    while (!pq.empty())
    {
        edge top = pq.top();
        int nowVertex = top.end, nowCost = top.cost;
        pq.pop();
        int len = adj[nowVertex].size();

        for (int i = 0; i < len; i++)
        {
            edge next = adj[nowVertex][i];
            int nextVertex = next.end, nextCost = next.cost;

            if (dist[nextVertex] > dist[nowVertex] + nextCost)
            {
                dist[nextVertex] = dist[nowVertex] + nextCost;
                pq.push(next);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        cin >> n >> d >> c; // c: startNode
        vector<edge> ad[MX];

        for (int i = 0; i < d; i++)
        {
            cin >> a >> b >> s;
            ad[b].push_back({a, s});
        }
        dijk(c, ad);

        int cnt = 0, sec = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] != INF)
            {
                cnt++;
                sec = max(sec, dist[i]);
            }
        }
        cout << cnt << " " << sec << "\n";
    }

    return 0;
}