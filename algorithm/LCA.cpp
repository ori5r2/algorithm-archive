#include <bits/stdc++.h>
using namespace std;
#define MX_K 17 // 2^17 >=MX // tree 높이
#define MX 100005
#define INF -1

int N, A, B;
vector<int> adj[MX]; // 트리 입력
int depth[MX];
int parent[MX_K + 1][MX]; // dp

void BFS()
{
    queue<int> q;
    q.push(1);                      // 루트
    depth[1] = 0, parent[0][1] = 1; // 루트 조상은 자기 자신

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        int len = adj[front].size();
        for (int i = 0; i < len; i++)
        {
            int frontChild = adj[front][i];
            if (depth[frontChild] == INF)
            {
                parent[0][frontChild] = front;
                depth[frontChild] = depth[front] + 1;
                q.push(frontChild);
            }
        }
    }
}

void DP()
{
    for (int i = 1; i <= MX_K; i++)
    {
        for (int j = 1; j <= N; j++)
        { // 부모의 부모
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
}

int LCA(int a, int b)
{
    // depth가 다를 때
    if (depth[a] > depth[b]) // a가 더 깊을 때
    {
        for (int k = MX_K; k >= 0; k--)
        {
            if (a != b && depth[parent[k][a]] >= depth[b])
                a = parent[k][a];
        }
    }

    if (depth[b] > depth[a]) // b가 더 깊을 때
    {
        for (int k = MX_K; k >= 0; k--)
        {
            if (a != b && depth[parent[k][a]] >= depth[a])
                b = parent[k][b];
        }
    }

    // depth가 같아짐
    // 조상이 같아질떄까지 올라감
    for (int k = MX_K; k >= 0; k--)
    {
        if (a != b && parent[k][a] != parent[k][b])
        {
            a = parent[k][a], b = parent[k][b];
        }
    }

    return (a == b) ? a : parent[0][a];
}

int main(void)
{
    // 초기화
    for (int i = 0; i <= N; i++)
        depth[i] = INF;

    BFS();
    DP();

    LCA(A, B);
}