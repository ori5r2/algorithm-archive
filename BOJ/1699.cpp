#include <bits/stdc++.h>
using namespace std;
#define MX 100005

int dp[MX];
int N;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int minVal = MX;
        for (int j = 1; j * j <= i; j++)
        {
            if (i == j * j)
            {
                minVal = 1;
                break;
            }
            minVal = min(minVal, dp[j * j] + dp[i - j * j]);
        }
        dp[i] = minVal;
    }
    cout << dp[N];

    return 0;
}