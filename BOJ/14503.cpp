#include <bits/stdc++.h>
using namespace std;
#define MX 52

int N, M, ans, tmp;
int r, c, d;
int board[MX][MX];
int visited[MX][MX];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void printBoard(int b[MX][MX])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (b[i][j] >= 10)
                cout << b[i][j] << " ";
            else
                cout << b[i][j] << "  ";
        }

        cout << endl;
    }
}

bool check(int X, int Y)
{
    bool ret = true;
    for (int i = 0; i < 4; i++)
    {
        int NX = X + dx[i], NY = Y + dy[i];
        if (!visited[NY][NX])
            ret = false;
    }
    return ret;
}

void BFS()
{
    queue<pair<int, int>> q;
    q.push({r, c}); // y, x
    ans = 1;
    // visited[r][c] = ans;

    while (!q.empty())
    {
        int y = q.front().first, x = q.front().second;
        q.pop();

        if (!visited[y][x])
            visited[y][x] = ans++;

        if (check(x, y)) // 청소가 다 된 경우
        {
            int dir;
            if (d == 0)
                dir = 2;
            else if (d == 1)
                dir = 3;
            else if (d == 2)
                dir = 0;
            else if (d == 3)
                dir = 1;

            int ny = y + dy[dir], nx = x + dx[dir];
            if (board[ny][nx] == 1)
                break;
            else
                q.push({ny, nx});
        }
        else // 청소가 안 된 방이 있는 경우
        {
            if (d == 0) // 반시계 방향으로 회전
                d = 3;
            else
                d -= 1;

            int ny = y + dy[d], nx = x + dx[d];

            if (!visited[ny][nx])
                q.push({ny, nx});
            else
                q.push({y, x});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            board[i][j] = tmp;
            visited[i][j] = tmp;
        }
    }

    // printBoard(board);
    BFS();
    // printBoard(visited);
    cout << ans - 1;
    return 0;
}