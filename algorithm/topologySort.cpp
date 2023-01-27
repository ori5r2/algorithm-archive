// 위상정렬
// 선후 관계 존재 (모두 다 정렬 x)
#include <bits/stdc++.h>
using namespace std;
#define MX 102

int N;
int inDegree[MX];
vector<int> adj[MX];

void topologySort()
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0) // 차수가 0인거 큐에 넣기 (초기화)
            q.push(i);
    }

    for (int i = 1; i <= N; i++)
    {
        if (q.empty())
            return;

        int front = q.front();
        q.pop();

        int adjSize = adj[front].size();
        for (int edge = 0; edge < adjSize; edge++)
        {
            int nowEdge = adj[front][edge];
            inDegree[nowEdge]--;

            if (inDegree[nowEdge] == 0)
                q.push(nowEdge);
        }
    }
}