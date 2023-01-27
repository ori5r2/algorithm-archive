#include <bits/stdc++.h>
using namespace std;
#define MX 102

struct edge
{
    int start;
    int end;
    int cost;
};

bool compare(edge a, edge b)
{
    return a.cost < b.cost;
}

int V, E, A, B;
int parent[MX];
vector<edge> vecEdge;

/* union & find */
void init()
{
    for (int i = 0; i <= V; i++)
        parent[i] = i;
}

int findParent(int a)
{
    if (parent[a] == a)
        return a;

    int ret = findParent(parent[a]);
    parent[a] = ret;
    return ret;
}

bool merge(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a == b)
        return false;

    parent[b] = a;
    return true;
}
/* ********* */

void MST()
{
    int totalCost = 0, cnt = 0, vecSize = vecEdge.size();
    sort(vecEdge.begin(), vecEdge.end(), compare); // cost대로 오름차순 정렬

    init();
    for (int i = 0; i < vecSize; i++)
    {
        if (merge(vecEdge[i].start, vecEdge[i].end)) // 아직 연결이 안되었다면 연결하고 cost계산
        {
            totalCost += vecEdge[i].cost, cnt++;
        }

        if (cnt == V - 1)
            break; // 모든 정점 다 연결됨
    }
}