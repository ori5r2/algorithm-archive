#include <bits/stdc++.h>
using namespace std;
#define MX 100005

int N, K;
int dist[MX];
queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K; // N:수빈, K:동생
    memset(dist, -1, sizeof(dist));
    dist[N] = 0;
    q.push(N);

    while (dist[K] < 0)
    {
        int x = q.front();
        int d = dist[x];
        q.pop();

        for (int i = 0; i < 3; i++)
        {
            int nx, nd = d + 1;
            if (i == 0)
                nx = x + 1;
            else if (i == 1)
                nx = x - 1;
            else if (i == 2)
                nx = x * 2;

            if (nx < 0 || nx >= MX || dist[nx] >= 0)
                continue;

            dist[nx] = nd;
            q.push(nx);
        }
    }

    cout << dist[K];
    return 0;
}