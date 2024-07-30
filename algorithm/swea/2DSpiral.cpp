// 나선형 알고리즘
// 방향을 바꾸면서 탐색

#include <bits/stdc++.h>
using namespace std;
#define MX 10

int board[MX][MX];
int N;
// 왼 아 오 위
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void spiralCCW()
{
    int y = N / 2, x = N / 2;
    int idx = 1;

    board[y][x] = idx++;
    for (int t = 0; t < (N / 2); t++)
    {
        int num[] = {2 * t + 1, 2 * t + 1, 2 * t + 2, 2 * t + 2};
        for (int d = 0; d < 4; d++)
        {
            for (int i = 0; i < num[d]; i++)
            {
                y = y + dy[d], x = x + dx[d];
                board[y][x] = idx++;
            }
        }
    }

    // 왼쪽 한 번 더
    for (int i = 0; i < N - 1; i++)
    {
        y = y + dy[0], x = x + dx[0];
        board[y][x] = idx++;
    }
}

void spiralCW()
{
    int y = N / 2, x = N / 2;
    int idx = 1;

    board[y][x] = idx++;
    for (int t = 0; t < (N / 2); t++)
    {
        // 오 아 왼 위
        int num[] = {2 * t + 2, 2 * t + 1, 2 * t + 1, 2 * t + 2};
        for (int d : {2, 1, 0, 3})
        {
            for (int i = 0; i < num[d]; i++)
            {
                y = y + dy[d], x = x + dx[d];
                board[y][x] = idx++;
            }
        }
    }

    // 오른쪽 한 번 더
    for (int i = 0; i < N - 1; i++)
    {
        y = y + dy[2], x = x + dx[2];
        board[y][x] = idx++;
    }
}

int main(void)
{
    N = 7;
    spiralCW();
    // spiralCCW();
    printBoard();
}

// 문제
// https://www.acmicpc.net/problem/20057
// https://www.acmicpc.net/problem/21611
