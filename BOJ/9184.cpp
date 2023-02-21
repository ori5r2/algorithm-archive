#include <bits/stdc++.h>
using namespace std;
#define MX 102

int x, y, z;
int dp[MX][MX][MX];

int func(int A, int B, int C)
{
    if (A <= 0 || B <= 0 || C <= 0)
        return 1;

    if (A > 20 || B > 20 || C > 20)
        return dp[20][20][20];

    return dp[A][B][C];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("../input.txt", "r", stdin);

    dp[0][0][0] = 1;

    for (int a = 0; a <= 20; a++)
    {
        for (int b = 0; b <= 20; b++)
        {
            for (int c = 0; c <= 20; c++)
            {
                if (a == 0 || b == 0 || c == 0)
                {
                    dp[a][b][c] = 1;
                    continue;
                }

                if (a < b && b < c)
                    dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
                else
                    dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
            }
        }
    }

    while (1)
    {
        cin >> x >> y >> z;
        if (x == -1 && y == -1 && z == -1)
            break;

        cout << "w(" << x << ", " << y << ", " << z << ") = " << func(x, y, z) << "\n";
    }

    return 0;
}