#include <bits/stdc++.h>
using namespace std;

int N, M, ans = 65;
int board[10][10];
bool visited[10][10];
struct cctv
{
    pair<int, int> pos;
    int num;
};
vector<cctv> cctvs;
// 오 아 왼 위
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dr[] = {0, 4, 2, 4, 4, 1};
int cctv_arr[10];

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void mv(int y, int x, int dir)
{
    int ny = y, nx = x;
    while (1)
    {
        ny = ny + dy[dir], nx = nx + dx[dir];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            break;
        if (board[ny][nx] == 6)
            break;

        visited[ny][nx] = true;
    }
}

int calc()
{
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!board[i][j])
            {
                if (!visited[i][j])
                    ret++;
            }
        }
    }
    return ret;
}

void backTracking(int k)
{
    if (k == cctvs.size())
    {
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < cctvs.size(); i++) // mv
        {
            cctv nowCCTV = cctvs[i];
            int d = cctv_arr[i];
            if (nowCCTV.num == 1)
                mv(nowCCTV.pos.first, nowCCTV.pos.second, d);
            else if (nowCCTV.num == 2)
                mv(nowCCTV.pos.first, nowCCTV.pos.second, d), mv(nowCCTV.pos.first, nowCCTV.pos.second, d + 2);
            else if (nowCCTV.num == 3)
                mv(nowCCTV.pos.first, nowCCTV.pos.second, d % 4), mv(nowCCTV.pos.first, nowCCTV.pos.second, (d + 1) % 4);
            else if (nowCCTV.num == 4)
            {
                for (int t = 0; t < 4; t++)
                {
                    if (t != d)
                        mv(nowCCTV.pos.first, nowCCTV.pos.second, t);
                }
            }
            else if (nowCCTV.num == 5)
            {
                for (int t = 0; t < 4; t++)
                    mv(nowCCTV.pos.first, nowCCTV.pos.second, t);
            }
        }
        // printBoard();
        // 사각지대 계산
        ans = min(ans, calc());
        return;
    }

    for (int i = 0; i < dr[cctvs[k].num]; i++)
    {
        cctv_arr[k] = i;
        backTracking(k + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6)
                cctvs.push_back({{i, j}, board[i][j]});
        }
    }

    backTracking(0);
    cout << ans;
    return 0;
}