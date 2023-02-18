// 시간초과: https://www.acmicpc.net/board/view/27386
#include <bits/stdc++.h>
using namespace std;
#define MX 1005

struct pos
{
    bool wall;
    int n, m;
};

int N, M;
string s;
int board[MX][MX];
int distFalse[MX][MX];
int distTrue[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void BFS()
{
    queue<pos> q;
    q.push({0, 0, 0}), distFalse[0][0] = 1;

    while (!q.empty())
    {
        int y = q.front().n, x = q.front().m;
        bool isBreak = q.front().wall;
        int d;
        if (isBreak)
            d = distTrue[y][x];
        else
            d = distFalse[y][x];
        q.pop();

        // cout << "q: " << y << " " << x << " " << d << endl;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;

            if (isBreak) // 벽을 부신 경우
            {
                // cout << ny << " " << nx << endl;
                if (distTrue[ny][nx])
                    continue;
                if (board[ny][nx] == 0)
                {
                    // cout << "T1 : " << ny << " " << nx << " " << endl;
                    q.push({true, ny, nx}), distTrue[ny][nx] = d + 1;
                }
            }
            else // 벽을 부시지 않은 경우
            {
                if (distFalse[ny][nx])
                    continue;

                if (board[ny][nx] == 0) // 빈 공간인 경우
                {
                    // cout << "F : " << ny << " " << nx << " " << endl;
                    q.push({false, ny, nx}), distFalse[ny][nx] = d + 1;
                }
                else // 벽인 경우
                {
                    // cout << "T2 : " << ny << " " << nx << " " << endl;
                    q.push({true, ny, nx}), distTrue[ny][nx] = d + 1;
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < M; j++)
            board[i][j] = s[j] - '0';
    }

    BFS();

    if (!distTrue[N - 1][M - 1] && !distFalse[N - 1][M - 1])
        cout << "-1";
    else if (!distTrue[N - 1][M - 1])
        cout << distFalse[N - 1][M - 1];
    else if (!distFalse[N - 1][M - 1])
        cout << distTrue[N - 1][M - 1];
    else if (distTrue[N - 1][M - 1] && distFalse[N - 1][M - 1])
        cout << min(distTrue[N - 1][M - 1], distFalse[N - 1][M - 1]);

    // cout << distTrue[N - 1][M - 1] << " " << distFalse[N - 1][M - 1];
    return 0;
}