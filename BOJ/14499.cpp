#include <bits/stdc++.h>
using namespace std;
#define MX 22

int direction[4][6] = {
    // 윗, 뒷, 옆동, 옆서, 앞, 밑
    // 1, 2, 3, 4, 5, 6
    {4, 2, 1, 6, 5, 3}, // 1: east
    {3, 2, 6, 1, 5, 4}, // 2: west
    {5, 1, 3, 4, 6, 2}, // 3: north
    {2, 6, 3, 4, 1, 5}  // 4: south
};

// 동서북남
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int dice[6];
int tmp[6];
int dir;
int board[MX][MX];
int N, M, X, Y, K;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M >> X >> Y >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 0; i < K; i++)
    {
        cin >> dir;

        int nx = X + dx[dir - 1], ny = Y + dy[dir - 1];

        // 지도 바깥으로 이동
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;

        // 주사위 굴리기
        for (int j = 0; j < 6; j++)
            tmp[j] = dice[direction[dir - 1][j] - 1];
        for (int j = 0; j < 6; j++)
            dice[j] = tmp[j];

        // 주사위 윗면
        cout << dice[0] << "\n";

        // 복사
        if (board[nx][ny])
        {
            dice[5] = board[nx][ny]; // 밑면
            board[nx][ny] = 0;
        }
        else // 칸에 쓰여 있는 수가 0
        {
            board[nx][ny] = dice[5];
        }
        X = nx, Y = ny;
    }

    return 0;
}