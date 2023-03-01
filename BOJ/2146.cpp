#include <bits/stdc++.h>
using namespace std;
#define MX 102

int N;
int minDist = INT_MAX;
int board[MX][MX];
int visited[MX][MX];
int dist[MX][MX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }
}

int BFS()
{
    queue<pair<int, int>> q;
    int idx = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] && !visited[i][j])
            {
                visited[i][j] = idx++;
                q.push({i, j});
            }

            while (!q.empty())
            {
                int y = q.front().first, x = q.front().second;
                int ix = visited[i][j];
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int ny = y + dy[d], nx = x + dx[d];

                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                        continue;

                    if (!board[ny][nx] || visited[ny][nx])
                        continue;

                    q.push({ny, nx});
                    visited[ny][nx] = ix;
                }
            }
        }
    }
    return idx;
}

void bridge(int idx)
{
    memset(dist, 0, sizeof(dist));
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == idx)
            {
                for (int d = 0; d < 4; d++)
                {
                    int ny = i + dy[d], nx = j + dx[d];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                        continue;
                    if (visited[ny][nx] == 0 && dist[ny][nx] == 0)
                    {
                        dist[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }

    while (!q.empty())
    {
        int y = q.front().first, x = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;

            if (dist[ny][nx])
                continue;

            if (!visited[ny][nx])
            {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
                continue;
            }

            if (visited[ny][nx] != idx)
            {
                // cout << visited[ny][nx] << " " << dist[y][x] << endl;
                minDist = min(minDist, dist[y][x]);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int cities = BFS();
    for (int i = 1; i < cities; i++)
    {
        bridge(i);
    }
    cout << minDist;

    return 0;
}