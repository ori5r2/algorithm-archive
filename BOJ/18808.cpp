#include <bits/stdc++.h>
using namespace std;
#define MX 45

int N, M, K, ans = 0;
int R, C;
int board[MX][MX];
int sticker[15][15];
int tmpSticker[15][15];

// void printBoard()
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//             fout << board[i][j];
//         fout << endl;
//     }
//     fout << endl;
// }

// void printSticker()
// {
//     for (int i = 0; i < R; i++)
//     {
//         for (int j = 0; j < C; j++)
//             fout << sticker[i][j];
//         fout << endl;
//     }
//     fout << endl;
// }

bool findSticker()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i + R > N || j + C > M)
                continue;

            bool suc = true;
            for (int r = i; r < i + R; r++)
            {
                if (!suc)
                    break;

                for (int c = j; c < j + C; c++)
                {
                    if (sticker[r - i][c - j])
                    {
                        if (board[r][c])
                        {
                            suc = false;
                            break;
                        }
                    }
                }
            }

            if (suc)
            {
                for (int r = i; r < i + R; r++)
                {
                    for (int c = j; c < j + C; c++)
                    {
                        if (sticker[r - i][c - j])
                            board[r][c] = 1;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void rotate()
{
    // 90도 회전
    memset(tmpSticker, 0, sizeof(tmpSticker));
    for (int j = 0; j < C; j++)
    {
        for (int i = R - 1; i >= 0; i--)
        {
            tmpSticker[j][R - 1 - i] = sticker[i][j];
        }
    }
    swap(R, C);

    memset(sticker, 0, sizeof(sticker));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            sticker[i][j] = tmpSticker[i][j];
}
void cntSticker()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j])
                ans++;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> R >> C;
        memset(sticker, 0, sizeof(sticker));
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> sticker[i][j];

        if (findSticker())
            continue;
        else
        {
            for (int t = 0; t < 3; t++)
            {
                rotate();
                if (findSticker())
                    break;
            }
        }
    }
    cntSticker();
    cout << ans;

    return 0;
}