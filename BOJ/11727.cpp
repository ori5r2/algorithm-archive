#include <bits/stdc++.h>
using namespace std;
#define MX 1002
#define DIV 10007

int N;
int dp[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);

    cin >> N;
    dp[1] = 1, dp[2] = 3;
    for (int i = 3; i <= N; i++)
        dp[i] = ((dp[i - 2] * 2) % DIV + dp[i - 1] % DIV) % DIV;

    // dp[i-2] + '=' or 'ㅁ'
    // dp[i-1] + 'ㅣ'

    cout << dp[N] % DIV;

    return 0;
}