#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
double H, W, N, M;
ll ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> H >> W >> N >> M;

    ans = (ceil(H / (1 + N))) * (ceil(W / (1 + M)));
    cout << ans;
    return 0;
}