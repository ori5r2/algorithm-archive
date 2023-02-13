#include <iostream>
#include <algorithm>
using namespace std;
#define MX 105
#define INF 1987654321

int N, M, A, B; // input
long long C;
long long dist[MX][MX];

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

    cin >> N >> M;

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

    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        dist[A][B] = min(dist[A][B], C);
    }

    Floyd();

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j || dist[i][j] == INF)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}