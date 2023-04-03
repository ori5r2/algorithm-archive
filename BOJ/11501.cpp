#include <bits/stdc++.h>
using namespace std;

int T, N;
int A[1000005];
int mx[1000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        long long val = 0;

        for (int i = 0; i < N; i++)
            cin >> A[i];

        mx[N - 1] = A[N - 1];

        for (int i = N - 2; i >= 0; i--)
            mx[i] = max(A[i], mx[i + 1]);

        for (int i = 0; i < N; i++)
            val += (mx[i] - A[i]);

        cout << val << "\n";
    }

    return 0;
}