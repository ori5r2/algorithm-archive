#include <bits/stdc++.h>
using namespace std;
#define MX 17

int N, t, p;
int T[MX], P[MX], dp[MX];
pair<int, int> input[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> t >> p;
        input[i] = {t, p};
    }

    for (int i = N; i > 0; i--)
    {
        int t = input[i].first, p = input[i].second;

        if (i + t - 1 > N)
            dp[i] = dp[i + 1];
        else
        {
            dp[i] = max(dp[i + 1], p + dp[i + t]);
        }
    }

    cout << dp[1];
    return 0;
}