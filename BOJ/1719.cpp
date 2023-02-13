#include <bits/stdc++.h>
using namespace std;
#define MX 202
#define INF 200002

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
int dist[MX], prior[MX];
int N, M;
int a, b, c;
int ans[MX][MX];

void dijk(int startNode)
{
    // 초기화
    priority_queue<edge> pq;
    for (int i = 0; i <= N; i++)
        dist[i] = INF, prior[i] = 0;
    dist[startNode] = 0, pq.push({startNode, 0});

    while (!pq.empty())
    {
        edge now = pq.top();
        int nowEnd = now.end, nowCost = now.cost;
        pq.pop();

        if (nowCost > dist[nowEnd])
            continue;

        int len = adj[nowEnd].size();
        for (int i = 0; i < len; i++)
        {
            edge next = adj[nowEnd][i];
            int nextEnd = next.end, nextCost = next.cost;

            if (dist[nextEnd] > dist[nowEnd] + nextCost)
            {
                dist[nextEnd] = dist[nowEnd] + nextCost;
                prior[nextEnd] = nowEnd;
                pq.push({nextEnd, dist[nextEnd]});
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

    for (int tc = 1; tc <= N; tc++)
    {
        dijk(tc);
        for (int nd = 1; nd <= N; nd++)
        {
            if (nd == tc)
                continue;

            int idx = nd;
            while (prior[idx] != tc)
            {
                idx = prior[idx];
            }
            ans[tc][nd] = idx;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                cout << "- ";
            else
                cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}