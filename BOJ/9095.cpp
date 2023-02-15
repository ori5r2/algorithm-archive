#include <bits/stdc++.h>
using namespace std;
#define MX 12

int T, N;
int dp[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> T;
    dp[0] = 1, dp[1] = 1, dp[2] = 2;

    for (int i = 3; i <= 11; i++)
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    //  i = 3 + (i-3)
    //  i = 2 + (i-2)
    //  i = 1 + (i-1)

    for (int tc = 0; tc < T; tc++)
    {
        cin >> N;
        cout << dp[N] << "\n";
    }

    return 0;
}