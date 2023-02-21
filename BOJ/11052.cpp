#include <bits/stdc++.h>
using namespace std;
#define MX 1002

typedef long long ll;
int N;
int P[MX];
ll dp[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i];

    for (int i = 1; i <= N; i++)
    {
        dp[i] = P[i];
        for (int k = 1; k <= (i / 2); k++)
            dp[i] = max(dp[i], dp[k] + dp[i - k]);
    }
    cout << dp[N];

    return 0;
}