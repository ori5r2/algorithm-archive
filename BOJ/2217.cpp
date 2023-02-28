#include <bits/stdc++.h>
using namespace std;
#define MX 100002

int N, maxVal;
int rope[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> rope[i];

    sort(rope, rope + N, greater<int>());
    for (int i = 0; i < N; i++)
    {
        int now = rope[i] * (i + 1);
        maxVal = max(maxVal, now);
    }

    cout << maxVal;

    return 0;
}