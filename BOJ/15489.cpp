#include <bits/stdc++.h>
using namespace std;
#define MX 35

int R, C, W;
int dp[MX][MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> W;

    dp[1][1] = 1;
    for (int i = 2; i < R + W; i++)
    {
        dp[i][1] = 1, dp[i][i] = 1;
        for (int j = 2; j < i; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }

    int ans = 0;
    for (int i = 0; i < W; i++)
        for (int j = 0; j <= i; j++)
            ans += dp[R + i][C + j];

    cout << ans;
    return 0;
}