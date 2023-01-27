#include <bits/stdc++.h>
using namespace std;
#define MX 5002

int N, dp[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r ", stdin); //
    cin >> N;

    dp[1] = -1, dp[2] = -1, dp[3] = 1, dp[4] = -1, dp[5] = 1;
    for (int i = 6; i <= N; i++)
    {
        int tmp1 = i - 5;
        if (dp[tmp1] != -1)
        {
            dp[i] = dp[5] + dp[tmp1];
            continue;
        }

        int tmp2 = i - 3;
        if (dp[tmp2] != -1)
        {
            dp[i] = dp[3] + dp[tmp2];
            continue;
        }

        dp[i] = -1;
    }

    cout << dp[N];
    return 0;
}