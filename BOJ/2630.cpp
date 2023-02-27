#include <bits/stdc++.h>
using namespace std;
#define MX 150

int N;
int board[MX][MX];
int ans[2];

int checkBoard(int n, int y, int x)
{
    int ck = board[y][x];
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (ck != board[i][j])
                return -1;
        }
    }

    return ck;
}

void func(int n, int y, int x)
{
    if (n == 1)
    {
        ans[board[y][x]]++;
        return;
    }

    int check = checkBoard(n, y, x);
    // cout << n << " " << y << " " << x << " " << check << endl;

    if (check == -1)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int ny = y + i * (n / 2), nx = x + j * (n / 2);
                func(n / 2, ny, nx);
            }
        }
    }
    else
    {
        ans[check]++;
    }
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

    func(N, 0, 0);
    cout << ans[0] << "\n";
    cout << ans[1];
    return 0;
}