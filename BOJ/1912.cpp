#include <bits/stdc++.h>
using namespace std;
#define MX 100002

int N;
int A[MX], sum[MX], dp[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("../input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sum[0] = A[0], dp[0] = A[0];
    for (int i = 1; i < N; i++)
    {
        int tmp = sum[i - 1] + A[i];
        sum[i] = max(tmp, A[i]);
        dp[i] = max(dp[i - 1], sum[i]);
    }

    cout << dp[N - 1];

    return 0;
}