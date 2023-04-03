#include <bits/stdc++.h>
using namespace std;

int N;
int A[1005];
int dp[1005];
int val = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
    {
        dp[i] = A[i];
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
        val = max(dp[i], val);
    }

    cout << val;
    return 0;
}