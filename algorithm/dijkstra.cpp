// 다익스트라
// 음이 아닌 가중 그래프 > 단일 쌍, 단일 출발, 단일 도착 최단 경로 문제
#include <bits/stdc++.h>
using namespace std;
#define MX 102 // 최대 노드 수
#define INF 1987654321

struct edge
{
    int end;
    int cost;

    bool operator<(const edge &b) const // 최소힙
    {
        return cost > b.cost;
    }
};
priority_queue<edge> pq;
int N;
int dist[MX];         // 최단 경로 길이
vector<edge> adj[MX]; // 그래프

void dijk(int startNode)
{
    // 초기화
    for (int i = 0; i <= N; i++)
        dist[i] = INF;
    pq.push({startNode, 0});
    dist[startNode] = 0;

    while (pq.empty())
    {
        edge top = pq.top();
        pq.pop();

        int nowVertex = top.end, nowCost = top.cost;
        int len = adj[nowVertex].size();

        if (nowCost > dist[nowVertex])
            continue; // 시간초과

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