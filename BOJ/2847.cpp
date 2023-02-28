#include <bits/stdc++.h>
using namespace std;
#define MX 105

int N;
int level[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> level[i];

    int high = level[N - 1];
    long long ans = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        if (level[i] >= high)
        {
            high = high - 1;
            ans += level[i] - high;
        }
        else
        {
            high = level[i];
        }
    }

    cout << ans;
    return 0;
}