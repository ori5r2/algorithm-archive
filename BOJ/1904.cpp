#include <bits/stdc++.h>
using namespace std;
#define MX 1000002
#define DIV 15746

int N;
int dp[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dp[1] = 1, dp[2] = 2;

    for (int i = 3; i <= N; i++)
        dp[i] = ((dp[i - 1] % DIV) + (dp[i - 2] % DIV)) % DIV; // (1 && dp[i-1]) + (00 &&dp[i-2])

    cout << dp[N];

    return 0;
}