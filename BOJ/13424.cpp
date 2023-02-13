#include <bits/stdc++.h>
using namespace std;
#define MX 102
#define INF 100009

int T, N, M, K;
int a, b, c, tmp;
int dist[MX][MX];
int fnd[MX];

void floyd()
{
    for (int tmp = 1; tmp <= N; tmp++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][tmp] + dist[tmp][j]);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        cin >> N >> M;
        // 초기화
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;
            }
        }

        for (int i = 0; i < M; i++)
        {
            cin >> a >> b >> c;
            dist[a][b] = min(dist[a][b], c);
            dist[b][a] = min(dist[b][a], c);
        }

        floyd();

        cin >> K;

        for (int i = 1; i <= K; i++)
            cin >> fnd[i];

        pair<int, int> p = {INF, 102};
        for (int i = 1; i <= N; i++)
        {
            int ret = 0;
            for (int j = 1; j <= K; j++)
                ret += dist[i][fnd[j]];

            p = min(p, {ret, i});
        }
        cout << p.second << "\n";
    }
    return 0;
}