#include <bits/stdc++.h>
using namespace std;
#define DIV 1000000000
#define MX 102
typedef long long ll;

int N;
ll dp[MX][10]; // dp[N][s] : N의 자리 수 중 첫번째 자리가 s일때 계단 수

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin); //
    cin >> N;

    for (int s = 0; s <= 9; s++)
        dp[1][s] = 1;

    for (int n = 2; n <= N; n++)
    {
        dp[n][0] = dp[n - 1][1] % DIV;
        for (int s = 1; s <= 8; s++)
            dp[n][s] = ((dp[n - 1][s - 1] % DIV) + (dp[n - 1][s + 1] % DIV)) % DIV;
        dp[n][9] = dp[n - 1][8] % DIV;
    }

    ll sum = 0;
    for (int s = 1; s <= 9; s++)
        sum = (sum + dp[N][s]) % DIV;

    cout << sum;
    return 0;
}