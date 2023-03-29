#include <bits/stdc++.h>
using namespace std;

int N, T, K, S;
pair<int, int> arr[102];
int dp[10002][102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> T;
    for (int i = 1; i <= N; i++)
    {
        cin >> K >> S;
        arr[i] = {K, S};
    }

    sort(arr + 1, arr + N + 1);
    for (int t = 1; t <= T; t++)
    {
        for (int idx = 1; idx <= N; idx++)
        {
            int tm = arr[idx].first, val = arr[idx].second;

            if (t < tm)
            {
                dp[t][idx] = dp[t][idx - 1];
            }
            else
            {
                dp[t][idx] = max(dp[t][idx - 1], dp[t - tm][idx - 1] + val);
            }
        }
    }

    cout << dp[T][N];

    return 0;
}