#include <bits/stdc++.h>
using namespace std;
#define MX 102
#define INF 1987654321

string str;
int N, M, board[MX][MX], dist[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void printBoard(int b[MX][MX])
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << b[j][i] << " ";
        cout << endl;
    }
}

void init()
{
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            dist[j][i] = INF;
}

void BFS()
{
    init();
    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 0;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        int cost = dist[x][y];
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx <= 0 || ny <= 0 || nx > N || ny > M)
                continue;

            if (board[nx][ny])
            {
                if (dist[nx][ny] > cost + 1)
                {
                    dist[nx][ny] = cost + 1;
                    q.push({nx, ny});
                }
            }
            else
            {
                if (dist[nx][ny] > cost)
                {
                    dist[nx][ny] = cost;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N >> M; // N : 가로 & M : 세로
    for (int i = 1; i <= M; i++)
    {
        cin >> str;
        for (int j = 1; j <= N; j++)
            board[j][i] = str[j - 1] - '0';
    }

    BFS();
    cout << dist[N][M];

    return 0;
}