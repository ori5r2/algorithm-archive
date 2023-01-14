#include <bits/stdc++.h>
using namespace std;
#define MX 105

int N, M;
string str;
int dist[MX][MX], board[MX][MX];
bool vis[MX][MX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;

void printBoard(int b[MX][MX])
{
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); // **

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
            board[i][j] = str[j] - '0';
    }

    q.push({0, 0});
    dist[0][0] = 1, vis[0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int d = dist[x][y];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nd = d + 1;

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (vis[nx][ny] || !board[nx][ny])
                continue;

            q.push({nx, ny});
            dist[nx][ny] = nd;
            vis[nx][ny] = 1;
        }
    }

    // printBoard(dist);
    cout << dist[N - 1][M - 1];
    return 0;
}