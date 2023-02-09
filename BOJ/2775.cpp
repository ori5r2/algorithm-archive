#include <bits/stdc++.h>
using namespace std;
#define MX 16

int T, K, N;
int dp[MX][MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> K >> N; // K층 N호
        for (int i = 0; i <= N; i++)
            dp[0][i] = i;

        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        cout << dp[K][N] << "\n";
    }

    return 0;
}