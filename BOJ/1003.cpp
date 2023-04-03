#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T, N;
pair<ll, ll> dp[41]; // {0 호출하는 횟수, 1 호출하는 횟수}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> T;
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    int idx = 1;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        if (N > idx)
        {
            for (int j = idx + 1; j <= N; j++)
                dp[j] = {dp[j - 1].first + dp[j - 2].first, dp[j - 1].second + dp[j - 2].second};

            idx = N;
        }
        cout << dp[N].first << " " << dp[N].second << "\n";
    }

    return 0;
}