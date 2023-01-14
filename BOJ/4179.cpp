#include <bits/stdc++.h>
using namespace std;
#define MX 1005

int R, C;
string str;
int dist[MX][MX], fire[MX][MX];
char board[MX][MX];
queue<pair<int, int>> fireQ, jihoon;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void printBoard(int bd[MX][MX])
{
    cout << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << bd[i][j] << " ";
        cout << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> R >> C;
    memset(fire, -1, sizeof(fire));
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < R; i++)
    {
        cin >> str;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = str[j];
            if (str[j] == 'J')
                jihoon.push({i, j}), dist[i][j] = 0;
            else if (str[j] == 'F')
                fireQ.push({i, j}), fire[i][j] = 0;
        }
    }

    while (!fireQ.empty()) // 불이 번지는 시간 계산
    {
        int x = fireQ.front().first, y = fireQ.front().second;
        int t = fire[x][y];
        fireQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], nt = t + 1;
            // cout << x << " " << y << " " << nx << " " << ny << endl;
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (board[nx][ny] == '#')
                continue;
            if (fire[nx][ny] >= 0)
                continue;
            fire[nx][ny] = nt;
            fireQ.push({nx, ny});
        }
    }
    // printBoard(fire);

    while (!jihoon.empty()) // jihoon
    {
        int x = jihoon.front().first, y = jihoon.front().second;
        int t = dist[x][y];
        jihoon.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], nt = t + 1;
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (board[nx][ny] == '#' || board[nx][ny] == 'F' || dist[nx][ny] >= 0)
                continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= nt) // fire[nx][ny] != -1 (-1이라면 갈 수 불이 없는 거)
                continue;

            dist[nx][ny] = nt;
            jihoon.push({nx, ny});
        }
    }

    // printBoard(dist);

    int ans = R * C;
    bool isPossible = false;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i != 0 && i != R - 1 && j != 0 && j != C - 1)
                continue;
            else
            {
                if ((board[i][j] == '.' || board[i][j] == 'J') && dist[i][j] >= 0)
                    ans = min(ans, dist[i][j]), isPossible = true;
            }
        }
    }

    if (isPossible)
        cout << ans + 1;
    else
        cout << "IMPOSSIBLE";
    return 0;
}