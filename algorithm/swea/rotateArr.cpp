// 배열 돌리기
#include <bits/stdc++.h>
using namespace std;
#define MX 10

int board[MX][MX];
int newBoard[MX][MX];
int N;

void printBoard(int b[MX][MX])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void init()
{
    int idx = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = idx++;
}

void rotate90CW()
{ // 시계방향으로 90도 회전
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            newBoard[i][j] = board[N - j - 1][i];
}
void rotate90CCW()
{ // 반시계방향으로 90도 회전
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            newBoard[i][j] = board[j][N - i - 1];
}

int main(void)
{
    N = 5;
    init();
    printBoard(board);
    rotate90CW();
    printBoard(newBoard);
    rotate90CCW();
    printBoard(newBoard);
}

// 문제
// https://www.acmicpc.net/problem/20058
// https://www.acmicpc.net/problem/23291
// https://www.acmicpc.net/problem/16926
