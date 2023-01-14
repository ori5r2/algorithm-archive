#include <bits/stdc++.h>
using namespace std;
#define MX 1005

int N, M, tmp, ans;
int board[MX][MX], dist[MX][MX];
bool vis[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
bool suc = true;

void printBoard(int b[MX][MX])
{
    cout << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << b[j][i] << " ";
        cout << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N >> M;

    for (int i = 0; i < M; i++) // 세로줄수
    {
        for (int j = 0; j < N; j++) // 가로줄수
        {
            cin >> tmp;
            board[j][i] = tmp;
            if (tmp == 1)
            {
                q.push({j, i});
                vis[j][i] = 1;
            }
            else if (tmp == -1)
            {
                dist[j][i] = -1;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int d = dist[x][y];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], nd = d + 1;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (board[nx][ny] != 0 || vis[nx][ny])
                continue;

            q.push({nx, ny});
            dist[nx][ny] = nd;
            vis[nx][ny] = 1;
            // printBoard(dist);
        }
    }
    // printBoard(dist);

    for (int i = 0; i < M; i++)
    {
        if (!suc)
            break;
        for (int j = 0; j < N; j++)
        {
            if (board[j][i] == 0 && !vis[j][i])
            {
                suc = false;
                break;
            }
            ans = ans > dist[j][i] ? ans : dist[j][i];
        }
    }

    if (!suc)
        cout << -1;
    else
        cout << ans;

    return 0;
}
