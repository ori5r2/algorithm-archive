#include <bits/stdc++.h>
using namespace std;
#define MX 503

int N;
int A[MX][MX];

// 왼 아 오 위
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct sand
{
    int dirY, dirX, r;
};

sand info[] = {
    // y, x, ration
    {-1, 0, 7},
    {-2, 0, 2},
    {-1, -1, 10},
    {-1, 1, 1},
    {1, 0, 7},
    {2, 0, 2},
    {1, -1, 10},
    {1, 1, 1},
    {0, -2, 5} // alpha
};
// info > left , right : 좌표 * -1, bottom: 좌표 반대로 *-1,up: 좌표 반대로
int ans;
pair<int, int> tornado;

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void mv(int direction)
{
    tornado = {tornado.first + dy[direction], tornado.second + dx[direction]};
    int a = A[tornado.first][tornado.second];
    A[tornado.first][tornado.second] = 0;
    int r = 0;
    for (int k = 0; k < 9; k++)
    {
        int ny, nx;
        if (direction == 0) // left
            ny = tornado.first + info[k].dirY, nx = tornado.second + info[k].dirX;
        else if (direction == 1) // bottom
            ny = tornado.first + (info[k].dirX * -1), nx = tornado.second + (info[k].dirY * -1);
        else if (direction == 2) // right
            ny = tornado.first + (info[k].dirY * -1), nx = tornado.second + (info[k].dirX * -1);
        else // up
            ny = tornado.first + info[k].dirX, nx = tornado.second + info[k].dirY;
        int ns = a * info[k].r / 100;

        r += ns;
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            ans += ns;
        else
            A[ny][nx] += ns;
    }
    // alpha 처리
    int ny = tornado.first + dy[direction], nx = tornado.second + dx[direction];
    int ns = a - r;

    if (ny < 0 || nx < 0 || ny >= N || nx >= N)
        ans += ns;
    else
        A[ny][nx] += ns;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    tornado = {N / 2, N / 2};

    for (int i = 0; i < (N / 2); i++)
    {
        int dir[] = {1, 2 * i + 1, 2 * (i + 1), 2 * (i + 1), 2 * (i + 1)};

        // 왼쪽
        for (int d = 0; d < dir[0]; d++)
            mv(0);

        // 아래
        for (int d = 0; d < dir[1]; d++)
            mv(1);

        // 오른쪽
        for (int d = 0; d < dir[2]; d++)
            mv(2);

        // 위쪽
        for (int d = 0; d < dir[3]; d++)
            mv(3);

        // 왼쪽
        for (int d = 0; d < dir[4]; d++)
            mv(0);
    }

    cout << ans;
    return 0;
}