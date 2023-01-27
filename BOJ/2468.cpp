#include <bits/stdc++.h>
using namespace std;
#define MX 102

int N, maxCnt = 1, tmp, maxH = 0, minH = 101;
int board[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void BFS(int h) // h이하는 잠겼다
{
    queue<pair<int, int>> q;
    bool visited[MX][MX];
    memset(visited, false, sizeof(visited));
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] > h && !visited[i][j])
            {
                q.push({i, j});
                visited[i][j] = true, cnt++;
            }

            while (!q.empty())
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d], ny = y + dy[d];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (visited[nx][ny] || board[nx][ny] <= h)
                        continue;

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    maxCnt = (maxCnt > cnt) ? maxCnt : cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            board[i][j] = tmp;
            minH = (minH > tmp) ? tmp : minH;
            maxH = (maxH > tmp) ? maxH : tmp;
        }
    }

    for (int height = minH; height < maxH; height++)
    {
        BFS(height);
    }
    cout << maxCnt;

    return 0;
}