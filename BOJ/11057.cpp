#include <bits/stdc++.h>
using namespace std;
#define MX 1002
#define DIV 10007

int N;
int dp[MX][10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i <= 9; i++)
        dp[1][i] = 1;

    for (int j = 2; j <= N; j++)
    {
        for (int i = 0; i <= 9; i++)
        {
            int tmp = 0;
            for (int k = i; k <= 9; k++)
            {
                tmp = ((tmp % DIV) + (dp[j - 1][k] % DIV)) % DIV;
            }
            dp[j][i] = tmp % DIV;
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++)
        ans = ((ans % DIV) + (dp[N][i] % DIV)) % DIV;

    cout << ans;
    return 0;
}