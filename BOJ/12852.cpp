#include <bits/stdc++.h>
using namespace std;
#define MX 1000005

int N;
int dp[MX];
int before[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 2; i <= N; i++)
    {
        int a = -1, b = -1, c = -1;
        int tmp1 = -1, tmp2 = -1;
        // 1. 3으로 나누어 떨어지면
        if (i % 3 == 0)
            a = dp[i / 3];

        // 2. 2로 나누어 떨어지면
        if (i % 2 == 0)
        {
            b = dp[i / 2];
            if (a != -1 && a <= b)
                tmp1 = a, tmp2 = i / 3;
            else
                tmp1 = b, tmp2 = i / 2;
        }
        else if (a != -1)
            tmp1 = a, tmp2 = i / 3;

        // 3. 1을 뺀다
        c = dp[i - 1];
        if (tmp1 == -1)
            tmp1 = c, tmp2 = i - 1;
        else // tmp가 있음
        {
            if (c < tmp1)
                tmp1 = c, tmp2 = i - 1;
        }

        dp[i] = tmp1 + 1, before[i] = tmp2;
    }

    cout << dp[N] << "\n";
    int idx = N;
    cout << idx << " ";
    while (before[idx])
    {
        cout << before[idx] << " ";
        idx = before[idx];
    }

    return 0;
}