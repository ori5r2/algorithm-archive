#include <bits/stdc++.h>
using namespace std;
#define MX 105
#define INF 1987654321

int N;
int dist[MX][MX];

void Floyd()
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

    // dist 초기화
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

    // 입력

    return 0;
}