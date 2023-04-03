#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, M, vip;
ll dp[45];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    ll val = 1;

    cin >> N >> M;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    int idx = 1;
    for (int i = 0; i < M; i++)
    {
        cin >> vip;
        val *= dp[vip - idx];
        idx = vip + 1;
    }
    val *= dp[N + 1 - idx];

    cout << val;
    return 0;
}