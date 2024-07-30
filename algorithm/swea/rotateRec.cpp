#include <bits/stdc++.h>
using namespace std;
#define MX 10

int rec[MX][MX];
int N, M;

void printBoard(int b[MX][MX])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void init()
{
    N = 3, M = 2;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            rec[i][j] = ++cnt;
    }
}

void rotate90()
{
    int newBoard[MX][MX];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            newBoard[j][N - 1 - i] = rec[i][j];
        }
    }
    swap(N, M);
    printBoard(newBoard);
}

int main(void)
{
    init();
    printBoard(rec);
    rotate90();
}