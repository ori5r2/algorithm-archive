#include <bits/stdc++.h>
using namespace std;
#define MX 1002
#define DIV 10007

typedef long long ll;
int N;
ll dp[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= N; i++)
        dp[i] = (dp[i - 1] % DIV + dp[i - 2] % DIV) % DIV;

    cout << dp[N] % DIV;
    return 0;
}