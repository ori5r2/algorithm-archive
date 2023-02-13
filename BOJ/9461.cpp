#include <bits/stdc++.h>
using namespace std;

int T, N;
long long dp[102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> T;
    dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;

    int idx = 6;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> N;

        while (idx <= N)
        {
            dp[idx] = dp[idx - 5] + dp[idx - 1];
            idx++;
        }
        cout << dp[N] << "\n";
    }

    return 0;
}