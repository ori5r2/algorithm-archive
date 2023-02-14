#include <bits/stdc++.h>
using namespace std;
#define MX 5002
#define INF 1987654321

// 시도1 : 최단 경로 모두 저장 > BFS로 건우 있는지 확인
// 시도2 : 마산까지 가는 최단 경로 = 민준 -> 건우 + 건우 -> 마산

struct edge
{
    int end;
    int cost;
    bool operator<(const edge &b) const
    {
        return cost > b.cost;
    }
};

int V, E, P;
int a, b, c;
int dist[MX];
vector<edge> adj[MX];
vector<int> prior[MX];
bool visited[MX];
priority_queue<edge> pq;
string ans[2] = {"GOOD BYE", "SAVE HIM"};

void dijk(int startNode)
{
    // 초기화
    for (int i = 0; i <= V; i++)
        dist[i] = INF;
    pq.push({startNode, 0}), dist[startNode] = 0;
    prior[startNode].push_back(0);

    while (!pq.empty())
    {
        int nowV = pq.top().end, nowCost = pq.top().cost;
        pq.pop();

        if (nowCost > dist[nowV])
            continue;

        int len = adj[nowV].size();
        for (int i = 0; i < len; i++)
        {
            edge next = adj[nowV][i];
            int nextV = next.end, nextCost = next.cost;

            if (dist[nextV] > dist[nowV] + nextCost)
            {
                // ⭐️ 이전까진 저장했던 것은 최단 경로 아니기 떄문에 지워준다. ⭐️
                prior[nextV].clear();
                prior[nextV].push_back(nowV);

                dist[nextV] = dist[nowV] + nextCost;
                pq.push({nextV, dist[nextV]});
            }
            else if (dist[nextV] == dist[nowV] + nextCost)
            {
                prior[nextV].push_back(nowV);
            }
        }
    }
}

void BFS()
{
    queue<int> q;
    q.push(V);
    visited[V] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        int len = prior[now].size();
        for (int i = 0; i < len; i++)
        {
            int next = prior[now][i];
            if (visited[next])
                continue;
            if (next == 0)
                continue;

            q.push(next);
            visited[next] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> V >> E >> P;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dijk(1);
    BFS();
    cout << ans[visited[P]];

    return 0;
}