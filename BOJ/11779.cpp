#include <bits/stdc++.h>
using namespace std;
#define MX 1002
#define INF 100000002

struct edge
{
    int end;
    int cost;

    bool operator<(const edge &b) const
    {
        return cost > b.cost;
    }
};

int N, M;
int a, b, c;
int st, nd; // st: 시작도시, nd: 도착도시
vector<edge> adj[MX];
priority_queue<edge> pq;
int dist[MX], prior[MX];

void dijk()
{
    // 초기화
    for (int i = 0; i <= N; i++)
        dist[i] = INF;

    pq.push({st, 0}), dist[st] = 0;

    while (!pq.empty())
    {
        edge now = pq.top();
        int nowVertex = now.end, nowCost = now.cost;
        pq.pop();

        if (nowCost > dist[nowVertex]) // 시간 초과 해결
            continue;

        int len = adj[nowVertex].size();
        for (int i = 0; i < len; i++)
        {
            edge next = adj[nowVertex][i];
            int nextVertex = next.end, nextCost = next.cost;

            if (dist[nextVertex] > dist[nowVertex] + nextCost)
            {
                dist[nextVertex] = dist[nowVertex] + nextCost;
                prior[nextVertex] = nowVertex;
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
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    cin >> st >> nd;

    dijk();
    cout << dist[nd] << "\n";

    int idx = nd;
    vector<int> v;
    v.push_back(nd);
    while (idx != st)
    {
        v.push_back(prior[idx]);
        idx = prior[idx];
    }

    int len = v.size();
    cout << len << "\n";
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";

    return 0;
}