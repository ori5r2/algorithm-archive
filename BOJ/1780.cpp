#include <bits/stdc++.h>
using namespace std;
#define MX 2190 // 3^7 = 2187

int N;
int board[MX][MX];
int ans[3]; // ans[0]: -1로만 채워진 종이 개수 ,
            // ans[1]: 0로만 채워진 종이 개수 ,
            // ans[2]: 1로만 채워진 종이 개수

int checkBoard(int n, int y, int x)
{
    int a = board[y][x];
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (board[i][j] != a)
                return 2;
        }
    }
    return a;
}

void selfFunc(int n, int y, int x) // n: 한변의 길이, yx: 시작 위치
{
    if (n == 1)
    {
        ans[board[y][x] + 1]++;
        return;
    }

    int check = checkBoard(n, y, x);

    if (check == 2)
    {
        // 변을 3개로 자르기 >> 재귀
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int ny = y + i * (n / 3), nx = x + j * (n / 3);
                selfFunc(n / 3, ny, nx);
            }
        }
    }
    else
        ans[check + 1]++;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    selfFunc(N, 0, 0);
    cout << ans[0] << "\n";
    cout << ans[1] << "\n";
    cout << ans[2] << "\n";
    return 0;
}