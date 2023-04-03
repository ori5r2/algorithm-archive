#include <bits/stdc++.h>
using namespace std;
#define DIV 1000000009

typedef long long ll;

int T, N;
ll dp[1000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> T;

    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    int idx = 3;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        if (!dp[N])
        {
            for (int it = idx + 1; it <= N; it++)
                dp[it] = (dp[it - 1] % DIV + dp[it - 2] % DIV + dp[it - 3] % DIV) % DIV;

            idx = N;
        }
        cout << dp[N] << "\n";
    }

    return 0;
}