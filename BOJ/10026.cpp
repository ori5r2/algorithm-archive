#include <bits/stdc++.h>
using namespace std;
#define MX 102

int N;
char board[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int BFS(bool blind)
{
    bool visited[MX][MX];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    char ch;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (!visited[i][j])
            {
                q.push({i, j}), visited[i][j] = true;
                ch = board[i][j];
                ans++;
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
                    if (visited[nx][ny])
                        continue;

                    if (!blind)
                    {
                        if (board[nx][ny] != ch)
                            continue;
                    }
                    else // 적록 색맹일때
                    {
                        if (ch == 'R' || ch == 'G')
                        {
                            if (board[nx][ny] == 'B')
                                continue;
                        }
                        else
                        {
                            if (board[nx][ny] != ch)
                                continue;
                        }
                    }
                    visited[nx][ny] = true, q.push({nx, ny});
                }
            }
        }
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    cout << BFS(false) << " " << BFS(true);

    return 0;
}