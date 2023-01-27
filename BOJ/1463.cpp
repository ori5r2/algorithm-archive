#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 2;
int N, dp[MX]; // dp[i] : N=i일때 1로 만들기 위해 사용하는 연산의 최솟값

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dp[1] = 0, dp[2] = 1, dp[3] = 1;

    for (int i = 4; i <= N; i++)
    {
        int tmp = i - 1;
        int val = dp[tmp];

        if (i % 3 == 0)
        {
            int tmp3 = i / 3;
            val = dp[tmp3] < val ? dp[tmp3] : val;
        }

        if (i % 2 == 0)
        {
            int tmp2 = i / 2;
            val = dp[tmp2] < val ? dp[tmp2] : val;
        }

        dp[i] = val + 1;
    }

    cout << dp[N];
    return 0;
}