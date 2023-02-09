#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int N;
bool dp[MX]; // true: SK & false: CY

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    dp[0] = false, dp[1] = true, dp[2] = false, dp[3] = true;
    for (int i = 4; i <= N; i++)
    {
        int x = i / 3;
        int y = i % 3;

        if (x % 2 == 0) // 상영 시작
            dp[i] = dp[y];
        else
            dp[i] = !dp[y];
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     if (dp[i])
    //         cout << i << " SK\n";
    //     else
    //         cout << i << " CY\n";
    // }
    if (dp[N])
        cout << "SK";
    else
        cout << "CY";

    return 0;
}