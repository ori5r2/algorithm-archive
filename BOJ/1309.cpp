#include <bits/stdc++.h>
using namespace std;
#define DIV 9901
#define MX 100002

int N;
int dp[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp[0] = 1, dp[1] = 3;

    for (int i = 2; i <= N; i++)
    {
        // dp[i] = 2* (dp[i - 1] % DIV + 2) % DIV +1; // 0, i
        // for (int k = i - 2; k >= 0; k--)
        //     dp[i] += (dp[k] * 2) % DIV;
        dp[i] = ((2 * dp[i - 1]) % DIV + (dp[i - 2]) % DIV) % DIV;
    }

    cout << dp[N] % DIV;
    return 0;
}