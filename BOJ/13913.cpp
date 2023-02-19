#include <bits/stdc++.h>
using namespace std;
#define MX 100002

int N, K;
int visited[MX];
int parent[MX];
int dx[] = {-1, 1, 2};
int ans = 0;

void BFS()
{
    queue<int> q;
    q.push(N), visited[N] = 1, parent[N] = -1;

    while (!q.empty())
    {
        int front = q.front();
        int sec = visited[front];
        q.pop();

        if (front == K)
            break;

        for (int i = 0; i < 3; i++)
        {
            int next = 0;
            if (i == 2)
                next = front * 2;
            else
                next = front + dx[i];

            if (next < 0 || next > 100000)
                continue;

            if (visited[next])
                continue;

            q.push(next);
            visited[next] = sec + 1, parent[next] = front;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);
    cin >> N >> K;

    BFS();
    cout << visited[K] - 1 << "\n";

    stack<int> s;
    int idx = K;
    while (idx != -1)
    {
        s.push(idx);
        idx = parent[idx];
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}