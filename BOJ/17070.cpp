// ⭐️ dp로 풀어보기!!
#include <bits/stdc++.h>
using namespace std;
#define MX 17

struct pipe
{
    int dir;
    pair<int, int> pos;
};

int N;
int board[MX][MX];
int cnt = 0;
// 가로 대각선 세로
int dx[] = {1, 1, 0};
int dy[] = {0, 1, 1};

void movePipe()
{
    queue<pipe> q;
    q.push({0, {0, 1}});

    while (!q.empty())
    {
        int d = q.front().dir, y = q.front().pos.first, x = q.front().pos.second;
        q.pop();

        if (y == N - 1 && x == N - 1)
            cnt++;

        for (int i = 0; i < 3; i++)
        {
            if (d == 0 && i == 2)
                continue;
            if (d == 2 && i == 0)
                continue;

            int nd = i, ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;

            if (board[ny][nx])
                continue;
            if (i == 1 && (board[ny - 1][nx] || board[ny][nx - 1]))
                continue;

            q.push({nd, {ny, nx}});
        }
    }
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

    movePipe();
    cout << cnt;
    return 0;
}