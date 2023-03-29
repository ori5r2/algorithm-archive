#include <bits/stdc++.h>
using namespace std;
#define MX 52

struct dust
{
    pair<int, int> pos;
    int amount;
};
vector<pair<int, int>> airPurifier;
int R, C, T, ans = 0; // T초 후 남아 있는 미세먼지 양
int board[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<dust> q;

void sumDust()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] > 0)
                ans += board[i][j];
        }
    }
}

void printBoard()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void spreadDust()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j])
            {
                int a = board[i][j] / 5;
                int cnt = 0;

                // 4방향 확산
                if (a <= 0)
                    continue;

                for (int d = 0; d < 4; d++)
                {
                    int ny = i + dy[d], nx = j + dx[d];

                    if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                        continue;

                    if (board[ny][nx] == -1)
                        continue;

                    q.push({{ny, nx}, a});
                    cnt++;
                }

                board[i][j] -= a * cnt;
            }
        }
    }

    while (!q.empty())
    {
        int ny = q.front().pos.first, nx = q.front().pos.second;
        board[ny][nx] += q.front().amount;
        q.pop();
    }

    // printBoard();
}

void airClear()
{
    // 공기청정기 위쪽 airPurifier[0].first
    int topPos = airPurifier[0].first;
    if (topPos - 1 >= 0)
        board[topPos - 1][0] = 0;

    for (int i = topPos - 2; i >= 0; i--)
    {
        if (board[i][0])
        {
            board[i + 1][0] = board[i][0];
            board[i][0] = 0;
        }
    }
    for (int i = 1; i < C; i++)
    {
        if (board[0][i])
        {
            board[0][i - 1] = board[0][i];
            board[0][i] = 0;
        }
    }

    for (int i = 1; i <= topPos; i++)
    {
        if (board[i][C - 1])
        {
            board[i - 1][C - 1] = board[i][C - 1];
            board[i][C - 1] = 0;
        }
    }
    for (int i = C - 2; i >= 1; i--)
    {
        if (board[topPos][i])
        {
            board[topPos][i + 1] = board[topPos][i];
            board[topPos][i] = 0;
        }
    }
    // printBoard();

    // 공기청정기 아래쪽
    int bottomPos = airPurifier[1].first;
    if (bottomPos + 1 < R)
        board[bottomPos + 1][0] = 0;

    for (int i = bottomPos + 2; i < R; i++)
    {
        if (board[i][0])
        {
            board[i - 1][0] = board[i][0];
            board[i][0] = 0;
        }
    }
    for (int i = 1; i <= C - 1; i++)
    {
        if (board[R - 1][i])
        {
            board[R - 1][i - 1] = board[R - 1][i];
            board[R - 1][i] = 0;
        }
    }
    for (int i = R - 2; i >= bottomPos; i--)
    {
        if (board[i][C - 1])
        {
            board[i + 1][C - 1] = board[i][C - 1];
            board[i][C - 1] = 0;
        }
    }
    for (int i = C - 2; i >= 1; i--)
    {
        if (board[bottomPos][i])
        {
            board[bottomPos][i + 1] = board[bottomPos][i];
            board[bottomPos][i] = 0;
        }
    }
    // printBoard();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == -1)
                airPurifier.push_back({i, j});
        }
    }

    for (int t = 0; t < T; t++)
    {
        // 1초동안 확산
        spreadDust();

        // 공기청정기
        airClear();
    }
    sumDust();
    cout << ans;

    return 0;
}