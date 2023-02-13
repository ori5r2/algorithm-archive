#include <bits/stdc++.h>
using namespace std;
#define MX 100005

int T, N;
int dp[2][MX];
int sticker[2][MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        memset(dp, 0, sizeof(dp));
        memset(sticker, 0, sizeof(sticker));

        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> sticker[0][i];
        for (int i = 0; i < N; i++)
            cin >> sticker[1][i];

        dp[0][N - 1] = sticker[0][N - 1];
        dp[1][N - 1] = sticker[1][N - 1];

        for (int i = N - 2; i >= 0; i--)
        {
            dp[0][i] = sticker[0][i] + max(dp[1][i + 1], dp[1][i + 2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i + 1], dp[0][i + 2]);
        }

        cout << max(dp[0][0], dp[1][0]) << "\n";
    }

    return 0;
}