#include <bits/stdc++.h>
using namespace std;
#define MX 10002

typedef long long ll;
ll K, N;
ll wire[MX];
ll low, mid, high, ans;
ll midVal;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        cin >> wire[i];
        high = max(high, wire[i]);
    }

    ll low = 0;
    high = high + 1;
    while (low < high)
    {
        ll mid = (low + high) / 2;
        midVal = 0;
        for (int i = 0; i < K; i++)
            midVal += (wire[i] / mid);

        if (N <= midVal)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid;
    }

    cout << ans;
    return 0;
}