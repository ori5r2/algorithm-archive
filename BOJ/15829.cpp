#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll r = 31, m = 1234567891;
ll p = 1, h;
int N;
string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    cin >> s;
    for (int i = 0; i < N; i++)
    {
        ll a = s[i] - 'a' + 1;
        if (i != 0)
            p = (p * r) % m;

        h = (h + ((a * p) % m)) % m;
    }
    cout << h;

    return 0;
}