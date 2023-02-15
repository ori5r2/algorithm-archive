#include <bits/stdc++.h>
using namespace std;
#define MX 50002
#define LIM 223

int N;
int dp[MX];
int sqaure[LIM + 1];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i <= LIM; i++)
        sqaure[i] = i * i;

    dp[1] = 1;
    int idx = 2;
    for (int i = 2; i <= N; i++)
    {
        if (i == idx * idx)
        {
            dp[i] = 1;
            idx++;
            continue;
        }

        int minVal = 5;
        for (int j = 1; j <= idx - 1; j++)
        {
            int tmp = dp[sqaure[j]] + dp[i - sqaure[j]];
            minVal = min(minVal, tmp);
        }
        dp[i] = minVal;
    }
    cout << dp[N];

    return 0;
}