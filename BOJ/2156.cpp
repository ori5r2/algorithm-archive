#include <bits/stdc++.h>
using namespace std;
#define MX 10002
// 반례: 6 1000 1000 1 1 1000 1000 (두 잔 연속 안 마시는 경우)
int A[MX];
long long dp[MX][4];
int N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    dp[0][1] = A[0], dp[1][1] = A[1], dp[0][3] = A[0];
    dp[1][2] = A[0] + A[1], dp[1][3] = A[0] + A[1];
    long long maxVal = dp[1][2];

    for (int i = 2; i < N; i++)
    {
        dp[i][0] = maxVal;
        dp[i][1] = dp[i - 2][3] + A[i];
        dp[i][2] = dp[i - 1][1] + A[i];
        maxVal = max(maxVal, dp[i][0]);
        maxVal = max(maxVal, dp[i][1]);
        maxVal = max(maxVal, dp[i][2]);
        dp[i][3] = maxVal;
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }
    cout << maxVal;

    return 0;
}