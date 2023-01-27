#include <bits/stdc++.h>
using namespace std;
#define MX 1 << 20

long long dp[MX], ans = 1;
int A, B, C;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> A >> B >> C;

    int idx = 0;
    dp[idx] = 1, idx++;

    while (B > 0)
    {
        if (idx == 1)
            dp[idx] = A % C;
        else
            dp[idx] = ((dp[idx - 1] % C) * (dp[idx - 1] % C)) % C;

        if (B % 2 == 1)
            ans = ((ans % C) * (dp[idx] % C)) % C;

        idx++, B /= 2;
    }
    cout << ans;

    return 0;
}