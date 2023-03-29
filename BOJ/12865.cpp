#include <bits/stdc++.h>
using namespace std;

int dp[100002][102];
pair<int, int> arr[102];
int N, K, w, v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> w >> v;
        arr[i] = {w, v};
    }

    sort(arr + 1, arr + N);

    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            w = arr[j].first, v = arr[j].second;
            if (i < w)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - w][j - 1] + v);
            }
        }
    }

    // for (int i = 1; i <= K; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[K][N];
    return 0;
}