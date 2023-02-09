#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int N, M, a, b, ans = 0;
vector<int> adj[MX];
bool visited[MX];

void BFS()
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            ans++;
            visited[i] = true;
            q.push(i);

            while (!q.empty())
            {
                int front = q.front();
                q.pop();
                int len = adj[front].size();

                for (int idx = 0; idx < len; idx++)
                {
                    int next = adj[front][idx];
                    if (visited[next] == false)
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        else
            continue;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    BFS();
    cout << ans;

    return 0;
}