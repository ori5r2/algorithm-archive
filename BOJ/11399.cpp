#include <bits/stdc++.h>
using namespace std;
#define MX 1002

int N, S;
long long ans;
int P[MX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> P[i];

    sort(P, P + N);
    for (int i = 0; i < N; i++)
    {
        S += P[i];
        ans += S;
    }
    cout << ans;

    return 0;
}