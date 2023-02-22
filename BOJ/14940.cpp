#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int N, M;
int board[MX][MX];
int visited[MX][MX];
queue<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void BFS()
{
    while (!q.empty())
    {
        int y = q.front().first, x = q.front().second;
        int d = visited[y][x];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i], nd = d + 1;

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (board[ny][nx] == 0)
                continue;

            if (visited[ny][nx] >= 0)
                continue;

            q.push({ny, nx});
            visited[ny][nx] = nd;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(visited, -1, sizeof(visited));
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                q.push({i, j});
                visited[i][j] = 0;
            }
            else if (board[i][j] == 0)
            {
                visited[i][j] = 0;
            }
        }
    }

    BFS();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}