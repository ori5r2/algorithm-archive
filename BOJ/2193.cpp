#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[100];
int N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1, dp[2] = 1;

    cin >> N;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[N];

    return 0;
}