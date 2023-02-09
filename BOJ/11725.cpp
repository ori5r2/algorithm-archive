#include <bits/stdc++.h>
using namespace std;
#define MX 100002

int N, a, b;
vector<int> adj[MX];
bool visited[MX];
int parent[MX];

void BFS()
{
    queue<int> q;
    q.push(1);
    visited[1] = true, parent[1] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        int len = adj[front].size();

        for (int i = 0; i < len; i++)
        {
            int next = adj[front][i];
            if (!visited[next])
            {
                visited[next] = true;
                parent[next] = front;
                q.push(next);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    BFS();
    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";

    return 0;
}