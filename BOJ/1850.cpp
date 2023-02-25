#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, ret;

ll gcd(ll A, ll B)
{
    ll r = A % B;
    if (r == 0)
        return B;
    else
        return gcd(B, r);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> a >> b;

    if (a >= b)
        ret = gcd(a, b);
    else
        ret = gcd(b, a);

    string str = "";
    for (int i = 0; i < ret; i++)
        str += "1";
    cout << str;

    return 0;
}