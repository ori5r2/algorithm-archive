#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int N, M, V, X, Y;
vector<int> adj[MX];
bool visitedB[MX], visitedD[MX];

void DFS()
{
    stack<int> s;
    s.push(V);

    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (visitedD[top])
            continue;

        cout << top << " ";
        visitedD[top] = true;

        int len = adj[top].size();
        for (int i = len - 1; i >= 0; i--)
        {
            int next = adj[top][i];

            if (visitedD[next])
                continue;

            s.push(next);
        }
    }
}

void BFS()
{
    queue<int> q;
    q.push(V);
    cout << V << " ";
    visitedB[V] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        int len = adj[front].size();
        for (int i = 0; i < len; i++)
        {
            int next = adj[front][i];
            if (visitedB[next])
                continue;

            q.push(next);
            cout << next << " ";
            visitedB[next] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    DFS();
    cout << "\n";
    BFS();

    return 0;
}