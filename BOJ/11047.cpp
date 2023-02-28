#include <bits/stdc++.h>
using namespace std;
#define MX 12

typedef long long ll;
int N, cnt;
ll K, A[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = N - 1; i >= 0; i--)
    {
        if (K == 0)
            break;

        if (K < A[i])
            continue;

        cnt += K / A[i];
        K = K % A[i];
    }

    cout << cnt;
    return 0;
}