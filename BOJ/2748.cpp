#include <bits/stdc++.h>
using namespace std;
#define MX 93

typedef long long ll;
int N;
ll dp[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[N];

    return 0;
}