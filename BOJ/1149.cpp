#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int N, a, b, c;
int dp[MX][3]; // dp[i][0]: i번째를 빨강을 선택했을 때 비용 최솟값
               // dp[i][1]: i번째를 파랑을 선택했을 때 비용 최솟값
               // dp[i][2]: i번째를 초록을 선택했을 때 비용 최솟값

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N;
    cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
    for (int i = 2; i <= N; i++)
    {
        cin >> a >> b >> c;
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + b;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + c;
    }

    cout << min({dp[N][0], dp[N][1], dp[N][2]});
    return 0;
}